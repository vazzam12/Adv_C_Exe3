#include <stdio.h>
#include "Stack.h"
#include "Queue.h"

void main()
{
	Stack Stack;
	Queue q;
	int num;
	init(&Stack);
	while (1) {
		switch (menu()) {
		case '1': printf("Enter the data: ");
			scanf_s("%d", &num);
			push(&Stack, num);
			display(&Stack);
			break;
		case '2': printf("\n Pop %d",
			pop(&Stack));
			display(&Stack);
			break;
		case '3': 
			isPalindrome(&Stack);
			display(&Stack);
			break;
		case '4':
			rotateStack(&Stack,5);
			display(&Stack);
			break;
		case '5':
			initQueue(&q);
			printQueue(&q);
			break;
		case '6':
			enqueue(&q, 5);
			printQueue(&q);
			break;
		case '7':
			dequeue(&q);
			printQueue(&q);
			break;
		case '8':
			printf("%d", isEmptyQueue(&q));
			break;
		case '9':
			rotateQueue(&q);
			printQueue(&q);
			break;
		case '10':
			cutAndReplace(&q);
			printQueue(&q);
			break;
		case '11':
			sortKidsFirst(&q);
			printQueue(&q);
			break;
		default: printf("\n Wrong. Pls try again");
		}// switch
	} // while
}// main



