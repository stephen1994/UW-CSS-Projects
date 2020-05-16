/**
 * Author: Stephen Choi
 * Last modification date: May 9th, 2020
 * CSS 430 Project3
 * Professor Jim Hogg
 * File Name: schedule_rr.c
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
// initialize a temporary linked list for reversing the order
struct node* temp = NULL;

void pickNextTask();
void reverseLinkedList();

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

	printf("-------------------------------Scheduling Round-Robin-------------------------------\n");
	reverseLinkedList();
	while (temp != NULL) {
		pickNextTask();
	}
	printf("------------------------------------------------------------------------------------\n");
}

// --------------------------------reverseLinkedList-------------------------------------- -
// Description
// reverseLinkedList: reverse the LinkedList 
// predonditions: NONE
// postconditions: reverse the order of head LinkedList to temp LinkedList 
// ----------------------------------------------------------------------------------
void reverseLinkedList() {
	
	while (head != NULL) {
		struct node* cur;
		struct node* picked;
		cur = head;
		picked = head;
		// pick the first node
		picked = cur;
		// insert the last node to the temporary linked list
		insert(&temp, picked->task);
		// delete the one that inserted 
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
		// move to next node
		current = current->next;
	}
}