#include "Queue.h"

/***************** Queue ADT Implementation *****************/

void initQueue(Queue* q)
{
	initList(&(q->queueList));
}

void destroyQueue(Queue* q)
{
	destroyList(&(q->queueList));
}

void enqueue(Queue* q, unsigned int data)
{
	addToTail(&(q->queueList), data);
}

unsigned int dequeue(Queue* q)
{
	return removeFromHead(&(q->queueList));
}

int isEmptyQueue(const Queue* q)
{
	return isEmptyList(&(q->queueList));
}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{
	Queue* tmp = q;

	while (tmp->queueList.head != tmp->queueList.tail)
	{

	}
}

void cutAndReplace(Queue* q)
{
	// add your code here
}

void sortKidsFirst(Queue* q)
{
	// add your code here
}
void printQueue(Queue* q)
{
	printList(&(q->queueList));
}