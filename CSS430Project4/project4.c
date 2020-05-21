/**
 * Author: Stephen Choi
 * Last modification date: May 20th, 2020
 * CSS 430 Project4
 * Professor Jim Hogg
 * File Name: P4.c
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MEMSIZE 80 /* The memory size */
#define MAX_LINE 20 /* MAX command line */

int main(int argc, char* argv[]) {

	char* args[MAX_LINE / 2 + 1]; /* command line arguments */

	int should_run = 1; /* flag to determine when to exit program */

	bool hist = false; // boolean to tell if there's history or not

	printf("-----------------------Instruction------------------------\nAllocation: A <name> <size> <algorithm>\n");
	printf("Free: F <name>\nShow: S\nCompact: C\nRead: R <filename>\nExit: E\n");
	printf("----------------------------------------------------------\n");

//-------------------memory pool array initialization---------------------
	char memory[MEMSIZE]; /* array of integers for the memory */
	memory[MEMSIZE] = '\0'; /* Null-terminated */
	for (int i = 0; i < MEMSIZE; i++) {  // initialize each element as '.'
		memory[i] = '.';
	}
//------------------------------------------------------------------------

	int count = 0; /* number of elements */

	while (should_run)
	{
		// Display shell prompt
		printf("> ");
		// clear the stdout buffer
		fflush(stdout);
		// char array to store command line
		char command[MAX_LINE + 1];
		// Read the command from standard input
		fgets(command, MAX_LINE + 1, stdin);
//---------------------------------------------------------------------------------
		if (strcmp(command, "S\n") == 0) {
			printf("%s\n", memory);
		}
//---------------------------------------------------------------------------------
		if (strcmp(command, "C\n") == 0) {
			bool done = false;
			while (done == false) {
				int i = 0;
				while (memory[++i] != '.');
				int j = i - 1;
				while (memory[++j] == '.');

				for (j; j < MEMSIZE; j++) {
					memory[i] = memory[j];
					i++;
				}

				for (int k = MEMSIZE - (j - i); k < MEMSIZE; k++) {
					memory[k] = '.';
				}

				// checking if compaciton is complete or not 
				// by if there's any '.' 
				int l = 0;
				while (memory[l++] != '.');
				if (l-1 == count)
					done = true;
			}
		}
//---------------------------------------------------------------------------------
		if (strcmp(command, "E\n") == 0) {
			printf("Program Terminated\n");
			should_run = 0;
		}
//---------------------------------------------------------------------------------
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
		if (strcmp(args[0], "A") == 0) {
			
			char allocate = *args[1];   // <name>
			int number = atoi(args[2]); // <size>        
			char algo = *args[3];       // <algo> 

			if (algo == 'F') {                                // First fit algorithm 

				int size = 0;                                 // empty memory size 
				int start = 0;                                // starting point of empty memory chunk

				for (int i = 0; i < MEMSIZE; i++) {
					if (memory[i] == '.') {
						size++;                               // counting the empty size of memory 
					}
					else if (memory[i] != '.') {
						start = i + 1;                        // start of empty memory
						size = 0;                             // reset the empty memory size, because it's a new chunk of memory
					}
					if (size >= number) {                     // if the size of chunk of memory is big enough
						for (int i = start; i < start + number; i++) {
							memory[i] = allocate;             // allocate the memory 
							count++;                          // increment the count 
						}
						break;                                // after allocation, break so it doesn't allocate again
					}
				}
			}
			else if (algo == 'B') {                           // Best fit algorithm
				int size = 0;                                 // empty memory size 
				int start = 0;                                // starting point of empty memory chunk
				int bestSize = MEMSIZE;                       // best memory chunk size
				int bestIndex = 0;                            // best starting index 

				for (int i = 0; i < MEMSIZE; i++) {
					if (memory[i] == '.' && i != MEMSIZE-1) {
						size++;                               // counting the empty size of memory 
					}
					else if (memory[i] != '.' || i == MEMSIZE-1) {
						start = i - size;                     // start of empty memory
						if (size >= number) {                 // if memory chunk is big enough
							if (size < bestSize) {            // if size of memory fit better than the previous
								bestSize = size;              // update the best size
								bestIndex = start;            // update the best index
							}
						}
						size = 0;                             // reset the empty memory size, because it's a new chunk of memory
					}
				}
				for (int i = bestIndex; i < bestIndex + number; i++) {
					memory[i] = allocate;					  // allocate the memory
					count++;                                  // increment the count 
				}
			}
			else if (algo == 'W') {					          // Worst fit algorithm
				int size = 0;                                 // empty memory size 
				int start = 0;                                // starting point of empty memory chunk
				int worstSize = 0;                            //  best memory chunk size
				int worstIndex = 0;                           // best starting index 

				for (int i = 0; i < MEMSIZE; i++) {
					if (memory[i] == '.' && i != MEMSIZE-1) {
						size++;                               // counting the empty size of memory 
					}
					else if (memory[i] != '.' || i == MEMSIZE-1) { 
						start = i - size;                     // start of empty memory
						if (size >= number) {                 // if memory chunk is big enough
							if (size > worstSize) {           // if size of memory fit better than the previous
								worstSize = size;             // update the worst size
								worstIndex = start;           // update the worst index
							}
						}
						size = 0;                             // reset the empty memory size, because it's a new chunk of memory
						 
					}
				}
				for (int i = worstIndex; i < worstIndex + number; i++) {
					memory[i] = allocate;					  // allocate the memory
					count++;                                  // increment the count 
				}
			}
			else {
				printf("ERROR: Wrong Algorithm\n");
				printf("-----------------------Instruction------------------------\nAllocation: A <name> <size> <algorithm>\n");
				printf("Free: F <name>\nShow: S\nCompact: C\nRead: R <filename>\nExit: E\n");
				printf("----------------------------------------------------------\n");
			}
		}
//---------------------------------------------------------------------------------	
		if (strcmp(args[0], "F") == 0){
			for (int i = 0; i < MEMSIZE; i++) {
				if (memory[i] == *args[1]) {
					memory[i] = '.';
					count--;
				}
			}
		}
//---------------------------------------------------------------------------------	
		if (strcmp(args[0], "R") == 0) {
			char command[15]; /* array of command */
			// file pointer
			FILE* readFile;
			// reading from file
			readFile = fopen(args[1], "r");
			// if it couldn't locate file, terminates the program
			if (readFile == NULL) {
				printf("ERROR: File could not be opened\n");
				return 0;
			}

			for (int i = 0; i < 15; i++) {
				fgets(command, 15, readFile); // read command line by line
				printf("%s", command); // print out command line by line

				char space[] = " ";

				// <command> <name> <size> <algo>
				char* ptr = strtok(command, space); // first character of the command
				if (*ptr == 'A') {       // Allocate <size> bytes for process <name> using algorithm <algo>.
					char allocate = *strtok(NULL, space);   // <name>
					int number = atoi(strtok(NULL, space)); // <size>
					char algo = *strtok(NULL, space);       // <algo> 

					if (algo == 'F') {                                // First fit algorithm 
						int size = 0;                                 // empty memory size 
						int start = 0;                                // starting point of empty memory chunk
						for (int i = 0; i < MEMSIZE; i++) {
							if (memory[i] == '.') {
								size++;                               // counting the empty size of memory 
							}
							else if (memory[i] != '.') {
								start = i + 1;                        // start of empty memory
								size = 0;                             // reset the empty memory size, because it's a new chunk of memory
							}
							if (size >= number) {                     // if the size of chunk of memory is big enough
								for (int i = start; i < start + number; i++) {
									memory[i] = allocate;             // allocate the memory 
									count++;                          // increment the count 
								}
								break;                                // after allocation, break so it doesn't allocate again
							}
						}
					}
					else if (algo == 'B') {                           // Best fit algorithm
						int size = 0;                                 // empty memory size 
						int start = 0;                                // starting point of empty memory chunk
						int bestSize = MEMSIZE;                       // best memory chunk size
						int bestIndex = 0;                            // best starting index 

						for (int i = 0; i < MEMSIZE; i++) {
							if (memory[i] == '.' && i != MEMSIZE - 1) {
								size++;                               // counting the empty size of memory 
							}
							else if (memory[i] != '.' || i == MEMSIZE - 1) {
								start = i - size;                     // start of empty memory
								if (size >= number) {                 // if memory chunk is big enough
									if (size < bestSize) {            // if size of memory fit better than the previous
										bestSize = size;              // update the best size
										bestIndex = start;            // update the best index
									}
								}
								size = 0;                             // reset the empty memory size, because it's a new chunk of memory
							}
						}
						for (int i = bestIndex; i < bestIndex + number; i++) {
							memory[i] = allocate;					  // allocate the memory
							count++;                                  // increment the count 
						}
					}
					else if (algo == 'W') {					          // Worst fit algorithm
						int size = 0;                                 // empty memory size 
						int start = 0;                                // starting point of empty memory chunk
						int worstSize = 0;                            //  best memory chunk size
						int worstIndex = 0;                           // best starting index 

						for (int i = 0; i < MEMSIZE; i++) {
							if (memory[i] == '.' && i != MEMSIZE - 1) {
								size++;                               // counting the empty size of memory 
							}
							else if (memory[i] != '.' || i == MEMSIZE - 1) {
								start = i - size;                     // start of empty memory
								if (size >= number) {                 // if memory chunk is big enough
									if (size > worstSize) {           // if size of memory fit better than the previous
										worstSize = size;             // update the worst size
										worstIndex = start;           // update the worst index
									}
								}
								size = 0;                             // reset the empty memory size, because it's a new chunk of memory
							}
						}
						for (int i = worstIndex; i < worstIndex + number; i++) {
							memory[i] = allocate;					  // allocate the memory
							count++;                                  // increment the count 
						}
					}
					else {
						printf("ERROR: Wrong Algorithm\n");
						printf("-----------------------Instruction------------------------\nAllocation: A <name> <size> <algorithm>\n");
						printf("Free: F <name>\nShow: S\nCompact: C\nRead: R <filename>\nExit: E\n");
						printf("----------------------------------------------------------\n");
					}		
//------------------------------------------------------------------------
				}
				else if (*ptr == 'F') {  // Free all allocations owned by process P
					char free = *strtok(NULL, space);  // character to free	
//------------------------------free--------------------------------------
					for (int i = 0; i < MEMSIZE; i++) {
						if (memory[i] == free) {
							memory[i] = '.';
							count--;
						}
					}
//------------------------------------------------------------------------

				}
				else if (*ptr == 'S') {  // Show the state of the memory pool
					printf("%s\n", memory);
				}
				else if (*ptr == 'R') {  // Read the script in the file called <file> and execute each command
				}
				else if (*ptr == 'C') {    // Compact the memory pool, sliding all allocations to lower addresses
					bool done = false;     // so they become one contiguous block, and so that all the free space
					while (done == false) {// lies to the right as one contiguous block
						int i = 0;
						while (memory[++i] != '.');
						int j = i - 1;
						while (memory[++j] == '.');

						// this copy over non-'.' to '.' places
						for (j; j < MEMSIZE; j++) {
							memory[i] = memory[j];
							i++;
						}
						// this move '.' that were replaced to the back of the array
						for (int k = MEMSIZE - (j - i); k < MEMSIZE; k++) {
							memory[k] = '.';
						}
						// checking if compaciton is complete or not 
						// by if there's any '.' 
						int l = 0;
						while (memory[l++] != '.');
						if (l - 1 == count)
							done = true;
					}
				}
				else {
					printf("This program does not support this command\n");
				}
			}
		}
	}
	return 0;
}