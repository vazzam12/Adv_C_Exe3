#include"list.h"
#include<stdio.h>
#include<stdlib.h>
/***************** Stack ADT Implementation *****************/

void initStack(Stack* s)
{
	s->head = NULL;
}

int isEmptyStack(const Stack* s)
{
	return (!(s->head));
}

void destroyStack(Stack* s)
{
	if (isEmptyStack(s))
	{
		printf("Stack is empty\n");
	}
	Stack* tmp = s;
	Stack* tmp1 = s;
	while (tmp1 != NULL)
	{
		tmp1 = tmp->head->next;
		free(tmp);
	}
}

void push(Stack* s, char data)
{
	charNode* newnode = (charNode*)malloc(sizeof(charNode));
	if (newnode == NULL) {
		printf("push: memory allocation problem\n");
		return;
	}
	newnode->data = data;
	s->head = addToHead(s->head, newnode);

}

char pop(Stack* s)
{
	char res;
	if (s->head == NULL) { printf("\nSTACK IS EMPTY"); return 0; }
	res = s->head->data;
	removeItem(&(s->head));//pop it from the stack
		return(res);
}




/*************** Functions using stacks - Implementation/definition **************************/

void flipBetweenHashes(const char* sentence)
{
	Stack* tmp;
	initStack(tmp);
	int flag = 0;
	int cnt = 0;
	for (int i = 0; sentence[i] != '\0'; i++)
	{

		if (sentence[i] == '#')
		{
			for (i; sentence[i] != '\0' && sentence != "#"; i++)
			{
				push(tmp, sentence[i]);
			}
		}
		if (tmp != NULL)
		{
			while (tmp != NULL)
			{
				printf("%c", pop(tmp));
			}
		}
		else
		{
			printf("%c", sentence[i]);
		}


	}
}

int isPalindrome(Stack* s)
{
	int size = 0;
	Stack* tmp = s;
	if (isEmptyStack(s))
	{
		return 1;
	}
	while (tmp->head!= NULL)
	{
		size++;
		tmp->head = tmp->head->next;
	}
	tmp = s;
	while (tmp->head != NULL)
	{

	}
	return 0;
}

void rotateStack(Stack* s, int n)
{
	// add your code here
}

void print(charNode* head)
{
	charNode* tmp;
	tmp = head;
	while (tmp != NULL) {
		printf(" % d ", tmp->data);
		tmp = tmp->next;
	}
}

void display(Stack* s)
{
	print(s->head);
}
