/*****************************************************************//**
 * \file   List_ADT.c
 * \brief
 *
 * \author Erez Yaakov Eines
 * \date   April 2022
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define LIST_END NULL
#define EMPTY_LIST NULL

#define LIST_POINTER_ERROR "Error - NULL pointer.\n"
#define BAD_ALLOC "Error - allocation error.\n"

 /**
  * Node implements a singly linked list (sll) node
  */
typedef struct Node
{
	char data; /**< The value stored in the node */
	struct Node* next; /**< Points to the next list element. can be NULL*/
}Node;

/**
 * Struct List is the managing structure for the ADT List.\n
 */
typedef struct List
{
	Node* head; //!< pointer to an sll Node. this is the list's head
	Node* tail; //!< pointer to an sll Node. this is the list's tail
} List;

/*AUXILARY FUNCTIONS*/
/**
 * \brief checks if the pointer "object" points to the NULL address.\n
 * object can be any pointer (int*, float*, List*, int**...).\n
 * any pointer type is implicitly cast into void*
 * \param object the object pointer to check for NULLity
 * \param message the error message to print to log file and std-err.
 * set message to NULL for empty message
 * \warning If this function recieves a NULL pointer as object parameter,\n
 *  it exits the running process that called it.
 * \private \memberof List
 */
void checkNullLogExit(const void* object, const char* message);

/**
 * \brief takes a newly created list and initializes it for use.\n
 *
 * \param list Pointer to the list being initialized.
 * \warning Users must call init on a newly created List object before using any of the public interface\n
 *		methods. calling any other method from the interface before init, results in undefined behaviour.
 * \public \memberof List
 * Ref checkNullLogExit()
 */
void initList(List* list);

/**
 * \brief adds an element to the head of the list.
 *
 * \param list Pointer to the list being initialized.
 * \param data The value to add as element at the head of the list.
 * \attention Assumes list has been properly initialized.
 * \public \memberof List
 */
void addToHead(List* list, int data);

/**
 * \brief removes the first element from a list and returns it's data value
 *
 * \param list The list to remove an element from.
 * \returns the first element in the list
 * \attention Assumes list has been properly initialized.
 * \warning Calling this method on an empty list results in process termination.
 * \public \memberof List
 * Ref checkNullLogExit()
 */
int removeFromHead(List* list);

/**
 * \brief adds a new element with value data to the end of a list.
 *
 * \param list The list to append an element to.
 * \param data The value to add as element at the tail of the list.
 * \attention Assumes list has been properly initialized.
 * \public \memberof List
 * Ref checkNullLogExit()
 */
void addToTail(List* list, int data);

/**
 * \brief finds the last element of the list, removes it and returns it's value.\n
 *
 * \param list The list to remove an element from.
 * \returns the last element in the list
 * \attention Assumes list has been properly initialized.
 * \warning Calling this method on an empty list results in process termination.
 * \public \memberof List
 * Ref checkNullLogExit()
 */
int removeFromTail(List* list);

/**
 * \brief outputs the list elements, from head through tail into the standard output.\n
 * this method does not change the list.
 * \param list The list to print.
 * \attention Assumes list has been properly initialized.
 * \public \memberof List
 */
void printList(const List* list);

/**
 * \brief checks if a list is empty.\n
 * this method does not change the list.
 * \param list The list to check for emptiness.
 * \returns 1 (true) if the list is empty, 0 (false) otherwise
 * \attention Assumes list has been properly initialized.
 * \attention Calling isEmpty on a destroyed list returns true but should be regarded as undefined behavior.
 * \public \memberof List
 * Ref checkNullLogExit()
 */
int isEmptyList(const List* list);

/**
 * \brief frees/deallocates all resources used by struct list\n
 *	- destroying an already destroyed list has no effect.\n
 *  - destroying a NULL pointer has no effect.
 * \param list - The list to destroy
 * \attention Assumes list has been properly initialized.
 * \warning destroying a list that has never been initialized results in undefined behavior
 * \warning once a list has been destroyed, do not re-use it by calling init.
 * \public \memberof List
 */
void destroyList(List* list);