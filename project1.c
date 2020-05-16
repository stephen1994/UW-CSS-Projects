/**
 * Author: Stephen Choi
 * Last modification date: April 16th, 2020
 * CSS 430 Project1
 * Professor Jim Hogg
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include<memory.h>
#include<assert.h>
#include<sys/wait.h>
#include<fcntl.h>
#include <ctype.h> 
#include <iostream>


#define MAX_LINE 80 /* The maximum length command */

int main(void)

{

	char* args[MAX_LINE / 2 + 1]; /* command line arguments */

	char history[MAX_LINE + 1]; // history array 

	int should_run = 1; /* flag to determine when to exit program */

	bool hist = false; // boolean to tell if there's history or not

	while (should_run)
	{
		// Display shell prompt
		printf("osh> ");
		// clear the stdout buffer
		fflush(stdout);		
		// char array to store command line
		char command[MAX_LINE + 1];
		// Read the command from standard input
		fgets(command, MAX_LINE + 1, stdin);
//---------------------------------------------------------------------------------
		// if command has !!
		if (strcmp(command, "!!\n") == 0) {
			// if there's no history 
			if (hist == false) {
				printf("No commands in history.\n");
			}
			else {
				// overwrite on command 
				for (int l = 0; l < MAX_LINE; l++)
					command[l] = history[l];
			}

		}
		else {
			// update history from the recent command 
			for (int l = 0; l < MAX_LINE; l++)
				history[l] = command[l];
			hist = true;
		}
//---------------------------------------------------------------------------------
		// If the command is to exit, set should_run to 0
		if (!strcmp(command, "exit\n")) {
			printf("Program will be exited.\n");
			exit(0);
		}
		else {
			command[strlen(command) - 1] = 0;
			// Tokenise the command using " "(whitespace) as delimiter
			char* token = strtok(command, " ");
			int i = 0;
			while (token != NULL)
			{
				// Store the token to the argument array
				args[i] = token;
				// Tokenise again. 
				token = strtok(NULL, " ");
				i++;
			}
			// Make the last argument NULL.
			args[i] = NULL;
//---------------------------------------------------------------------------------		   
			// get how many elements are in the array 
			int length = 0;
			while (args[length] != NULL)
			{
				length++;
			}
//---------------------------------------------------------------------------------		  
			// for ls, ls -al
			if (0 <= length && length <= 2) {
				int pid = fork();
				assert(pid != -1); // check for bugs in program
				if (pid < 0) {
					fprintf(stderr, "FORK Failed\n");
					return 1;
				}
				else if (pid == 0) { // child 
					// run command
					execvp(args[0], args);
				}
				else {  // parent
					// wait for the child
					wait(NULL);
				}
			}
//---------------------------------------------------------------------------------		 
			// for &, ;
		else if (strcmp(args[1], "&") == 0) {
				
				// when there's ; at the end
				if(length == 4 && strcmp(args[3], ";") == 0){
					args[1] = NULL;
					args[3] = NULL;
				}else{ // when there's no ; at the end
					args[1] = NULL;
				}
				
				int	pid = fork();
				assert(pid != -1); // check for bugs in program

				if (pid < 0) {
					fprintf(stderr, "FORK Failed\n");
					return 1;
				}
				else if (pid == 0) { // child
					// run command
					execvp(args[0], args);
				}
				else { // parent
					int pid2 = fork();
					assert(pid2 != -1); // check for bugs in program
					
					if (pid2 == 0) { // grand child
						// run command after & or ;
						execvp(args[2], args);
					}
					else {
						// wait for the grand child
						wait(NULL);
					}
					// wait for the child
					wait(NULL);
				}
			}
//---------------------------------------------------------------------------------				
			// for >
			else if (strcmp(args[1], ">") == 0) {
				
				args[length - 2] = NULL;
				int pid = fork();
				assert(pid != -1); // check for bugs in program
				
				if (pid < 0) {
					fprintf(stderr, "FORK Failed\n");
					return 1;
				}
				else if (pid == 0) { // child
					// file pointer
					FILE* fptr = NULL;
					char ch;
					// creates file with user input
					fptr = fopen(args[2], "w");
					// open file
					int file_desc = open(args[2], O_WRONLY | O_APPEND);
					// clear buffer
					fflush(stdout);
					// redirect stdout to pipe
					dup2(file_desc, STDOUT_FILENO);
					// execute the command
					execvp(args[0], args);
				}
				else { // parent
				// wait for the child
					wait(NULL);
				}
			}
//---------------------------------------------------------------------------------				
			else if (strcmp(args[1], "<") == 0) {
				
				args[length - 2] = NULL;
				int pid = fork();
				assert(pid != -1); // check for bugs in program
				
				if (pid < 0) {
					fprintf(stderr, "FORK Failed\n");
					return 1;
				}
				else if (pid == 0) { // child
					// file pointer
					FILE* fptr = NULL;
					// constant max size of char
					const int CHUNK = 1024;
					char ch[CHUNK];
					size_t nread;
					// open the file 
					fptr = fopen(args[2], "r");

					if (fptr) {
						while ((nread = fread(ch, 1, sizeof ch, fptr)) > 0)
							fwrite(ch, 1, nread, stdout);
						if (ferror(fptr)) {
							printf("FILE OPENING ERROR.");
						}
						fclose(fptr);
					}
				}
				else { // parent
				// wait for the child
					wait(NULL);
				}
			}
//---------------------------------------------------------------------------------
			// for the ls | wc		
			else if (strcmp(args[1], "|") == 0)
			{
				args[1] = NULL;
				int pid = fork();
				assert(pid != -1); // check for bugs in program
				int fd[2];

				if (pid < 0)
				{
					perror("Fork failed");
					exit(1);
				}

				else if (pid == 0) // child 
				{
					pipe(fd);
					pid = fork(); //fork again

					if (pid < 0)
					{
						perror("Fork failed");
						exit(1);
					}

					else if (pid == 0)
					{
						close(0);
						dup2(fd[0], 0);
						close(fd[1]);
						execvp(args[2], args + 2);
					}

					else
					{
						close(1);
						dup2(fd[1], 1);
						close(fd[0]);
						execvp(args[0], args);
					}

				}

				else
				{
					wait(NULL);
					wait(NULL);

				}
			}
			else {
				printf("Command is Not implemented yet or does not exist");
			}
		}
	}
	return 0;
}