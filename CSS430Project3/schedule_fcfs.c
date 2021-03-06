/**
 * Author: Stephen Choi
 * Last modification date: May 9th, 2020
 * CSS 430 Project3
 * Professor Jim Hogg
 * File Name: schedule_fcfs.c
 */

#include "schedulers.h"
#include "task.h"
#include "list.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MIN_PRIORITY 1
#define MAX_PRIORITY 10

// length of a time quantum
#define QUANTUM 10


// initialize the linked list
struct node* head = NULL;

void pickNextTask();

// --------------------------------add-------------------------------------- -
// Description
// add: Initialize a task and add to the left of the list
// predonditions: parameters are not NULL
// postconditions: create newTsk and insert it to the linked list
// ----------------------------------------------------------------------------------
void add(char* name, int priority, int burst) {	
	
	// allocate task
	Task* newTask = malloc(sizeof(Task));

	// assign the data
	newTask->name = name;
	newTask->priority = priority;
	newTask->burst = burst;
	
	// insert the new Task to the list
	insert(&head, newTask);

}

// --------------------------------schedule-------------------------------------- -
// Description
// schedule: schedule the process running upon the scheduling algorithm 
// predonditions: NONE
// postconditions: call pickNextTask
// ----------------------------------------------------------------------------------
void schedule() {
	printf("-------------------------------Scheduling FCFS-------------------------------\n");
	while (head != NULL) {
		pickNextTask();
	}
	printf("------------------------------------------------------------------------------------\n");

}

// --------------------------------pickNextTask-------------------------------------- -
// Description
// pickNextTask: Determine task to execute on the CPU by invoking run
// predonditions: NONE
// postconditions: print out output for the next Task   
// ----------------------------------------------------------------------------------
void pickNextTask() {
	struct node* current;
	current = head;
	
	// get the last node 
	while(current->next != NULL){
		current = current->next;
	}
	// print output
	run(current->task, current->task->burst);
	// delete the one that printed 
	delete(&head, current->task);
}
