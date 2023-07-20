#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "queue.h"
#include "random.h"

void initQueue()
{
	front = NULL;
	rear = NULL;  // initialising both front and rear of queue to NULL
}

bool isQueueEmpty()
{
	return front == NULL; //checking if the queue is empty by checking if the front is NULL or not
}
// function to enqueue a node to a queue
void enqueue(struct Node* temp)
{
	temp = (struct Node*)malloc(sizeof(struct Node)); // allocating space for the new node
	if (temp == NULL)  //checking if memory has been allocated
	{
		printf("Memory allocation error\n");
		return;
	}
	//storing a random username in the global variable result
	char* result = getRandomUsername();
	strncpy(temp->userName, result, 11);   //copying data members 
	temp->level = getRandomLevel();
	temp->faction = getRandomFaction();
	temp->next = NULL;
	if (isQueueEmpty())   //if queue is empty, set front and rear to temp
		front = rear = temp;
	else
	{
		rear->next = temp;   // else add temp to next of rear and set its value to temp
		rear = temp;
	}
}

//function to dequeue a element from a queue
struct Node* dequeue()
{
	if (isQueueEmpty())
		return NULL;
	//getting the front element of the queue and returning it and moving the front pointer to the right
	struct Node* temp = front;
	front = front->next;
	return temp;
}
