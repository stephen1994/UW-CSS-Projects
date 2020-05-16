/**
 * Author: Stephen Choi
 * Last modification date: May 11th, 2020
 * CSS 430 Project3
 * Professor Jim Hogg
 * File Name: schedule_priority_rr.c
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

// Temporary linked list for Round Robin
struct node* temp = NULL;

void priorityList();
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
// postconditions: call priorityList & pickNextTask
// ----------------------------------------------------------------------------------
void schedule() {

	printf("----------------------------Scheduling Priority Round-Robin--------------------------\n");

	// create priority ordered linked list
	priorityList();

	while (temp != NULL) {
		pickNextTask();
	}
	printf("------------------------------------------------------------------------------------\n");
}

// --------------------------------priorityList-------------------------------------- -
// Description
// priorityList: create temporary linked list in priority order
// predonditions: NONE
// postconditions: Using temp linked list, create linked list in priority order
// ----------------------------------------------------------------------------------
void priorityList() {

	while (head != NULL) {
		struct node* picked;
		struct node* cur;
		cur = head;
		picked = head;
		// pick the lowest priority
		while (cur != NULL) {
			// compare the Priority time
			if (cur->task->priority < picked->task->priority) {
				// pick the lowest priority (Number is low) 
				picked = cur;
			}
			// move to next node
			cur = cur->next;
		}
		// insert to the temp linked list
		insert(&temp, picked->task);
		// delete from the linked list
		delete(&head, picked->task);
	}
}

// --------------------------------pickNextTask-------------------------------------- -
// Description
// pickNextTask: Determine task to execute on the CPU by invoking run
// predonditions: NONE
// postconditions: print out output for the next Task   
// ----------------------------------------------------------------------------------
void pickNextTask() {

	struct node* current;
	current = temp;

	// if current is the last task 
	if (current->next == NULL) {
		while (current != NULL) {
			if (current->task->burst <= QUANTUM) {
				run(current->task, current->task->burst);
				delete(&temp, current->task);
				break;
			}
			else {
				// if CPU burst time remainder is greater than QUANTUM
				run(current->task, QUANTUM);
				// subtract 1 QUANTUM from CPU burst time 
				current->task->burst = current->task->burst - QUANTUM;
			}
		}
	}
	// if next task's priority is same as the current task
	else if (current->task->priority == current->next->task->priority) {
		// Do one Round 
		while (current != NULL) {
			// if CPU burst time remainder is less or equal than QUANTUM
			if (current->task->burst <= QUANTUM) {
				run(current->task, current->task->burst);
				delete(&temp, current->task);
			}
			else {
				// if CPU burst time remainder is greater than QUANTUM
				run(current->task, QUANTUM);
				// subtract 1 QUANTUM from CPU burst time 
				current->task->burst = current->task->burst - QUANTUM;
			}

			// break if current is the last process
			if (current->next == NULL)
				break;
			// break if next task's priority is different
			// it will start over from the head 
			else if (current->task->priority != current->next->task->priority)
				break;
			// move to next node
			else if (current->next != NULL)
				current = current->next;
		}
	}
	else { // when there are no same priority tasks
		while (current != NULL) {
			if (current->task->burst <= QUANTUM) {
				run(current->task, current->task->burst);
				delete(&temp, current->task);
				break;
			}
			else {
				// if CPU burst time remainder is greater than QUANTUM
				run(current->task, QUANTUM);
				// subtract 1 QUANTUM from CPU burst time 
				current->task->burst = current->task->burst - QUANTUM;
			}
		}
	}
}