#include"list.h"
#include<stdio.h>
#include<stdlib.h>
charNode* addToHead(charNode* head, charNode* toAdd) {
	toAdd->next = head;
	head = toAdd;
	return head;
}

void removeItem(charNode** head)
{
	if (*head == NULL) return; //if stack empty
	charNode* tmp = *head;
	*head = (*head)->next;
	free(tmp);
}

void print(charNode* head)
{
	charNode* tmp;
	tmp = head;
	while (tmp != NULL) {
		printf(" % c ", tmp->data);
		tmp = tmp->next;
	}
}


void initList(List* list)
{
	checkNullLogExit(list, LIST_POINTER_ERROR);
	list->head = list->tail = EMPTY_LIST;
}

void checkNullLogExit(const void* object, const char* message)
{
	if (object == NULL)
	{
		FILE* logErrors = NULL;
		fopen_s(&logErrors, "logErrors.txt", "w");
		if (logErrors != NULL && message != NULL)
		{
			fprintf(logErrors, "%s", message);
			fprintf(stderr, "%s", message);
		}
		exit(EXIT_FAILURE);
	}
}

unsigned int removeFromHead(List* list)
{
	checkNullLogExit(list, LIST_POINTER_ERROR);
	checkNullLogExit(list->head, LIST_POINTER_ERROR);

	unsigned int toReturn = list->head->data; //save return value
	Node* temp = list->head->next; //save new list head
	free(list->head);
	list->head = temp;//update list
	//check if list has become empty after removal
	if (list->head == EMPTY_LIST)
	{
		list->tail = EMPTY_LIST;//update list
	}
	return toReturn;
}

void printList(const List* list)
{
	checkNullLogExit(list, LIST_POINTER_ERROR);

	if (list->head == EMPTY_LIST)
	{
		printf("Empty List\n");
		return;
	}

	Node* temp = list->head;
	while (temp != LIST_END)
	{
		printf("%d->", temp->data);
		temp = temp->next;
	}

	printf("NULL\n");
}

void addToTail(List* list, unsigned int data)
{
	checkNullLogExit(list, LIST_POINTER_ERROR);
	//create new list node
	Node* newTail = (Node*)calloc(1, sizeof(Node));
	checkNullLogExit(newTail, BAD_ALLOC);
	newTail->data = data;
	//case this is very first list element added to empty list
	if (list->tail == EMPTY_LIST)
	{
		list->head = list->tail = newTail;//update list
		return;
	}
	else //list has at least one element
	{
		list->tail->next = newTail;
		list->tail = newTail;//update list
	}
}

int isEmptyList(const List* list)
{
	checkNullLogExit(list, LIST_POINTER_ERROR);
	//double check for testing purposes
	return (list->head == EMPTY_LIST && list->tail == EMPTY_LIST);
}

void destroyList(List* list)
{
	if (list == NULL)
	{
		return;
	}

	Node* toDestroy = list->head;
	Node* next;
	while (toDestroy != LIST_END)
	{
		next = toDestroy->next;
		free(toDestroy);
		toDestroy = next;
	}

	list->head = list->tail = EMPTY_LIST;//update list
}

void addToHead_list(List* list, unsigned int data)
{
	checkNullLogExit(list, LIST_POINTER_ERROR);
	//create new list node
	Node* newHead = (Node*)calloc(1, sizeof(Node));
	checkNullLogExit(newHead, BAD_ALLOC);
	newHead->data = data;
	//case this is very first list element added to empty list
	if (list->head == EMPTY_LIST)
	{
		list->head = list->tail = newHead;//update list
	}
	else //list has at least one element
	{
		newHead->next = list->head;
		list->head = newHead;//update list
	}
}

unsigned int removeFromTail(List* list)
{
	checkNullLogExit(list, LIST_POINTER_ERROR);
	checkNullLogExit(list->head, LIST_POINTER_ERROR);
	//temp nodes to iterate over list and find the element previous to tail
	Node* current = list->head;
	Node* previous = NULL;
	while (current->next != LIST_END)
	{
		previous = current;
		current = current->next;
	}

	unsigned int toReturn = current->data;//save return value
	free(current);
	list->tail = previous;//update list
	//check if list has become empty after removal
	if (list->tail == EMPTY_LIST)
	{
		list->head = EMPTY_LIST;//update list
	}
	else
	{
		list->tail->next = LIST_END;//update tail to point to null (was previously pointing to freed element)
	}

	return toReturn;
}