#include "List.h"

//admin struct for Queues
typedef struct queue
{
	List queueList;
}Queue;

/// <summary>
/// Initializes a Queue ADT structure.
/// 
///	A Queue cannot be used before init. the owner of the Queue MUST
/// init the Queue before use.
/// 
///	Uninitialized use of a Queue results in undefined behaviour.
/// 
/// Initializing an already initialized Queue results in undefined behaviour.
/// </summary>
/// 
/// <assumption> q != nullptr </assumption>
/// 
/// <param name="q"> a non null pointer to a struct Queue</param>
void initQueue(Queue* q);

/// <summary>
/// 
/// </summary>
/// <param name="q"></param>
void destroyQueue(Queue* q);

/// <summary>
/// 
/// </summary>
/// <param name="q"></param>
/// <param name="data"></param>
void enqueue(Queue* q, unsigned int data);

/// <summary>
/// 
/// </summary>
/// <param name="q"></param>
/// <returns></returns>
unsigned int dequeue(Queue* q);

/// <summary>
/// 
/// </summary>
/// <param name="q"></param>
/// <returns></returns>
int isEmptyQueue(const Queue* q);

/*************** Functions using Queues - Declaration **************************/

/// <summary>
/// 
/// </summary>
/// <param name="s"></param>
void rotateQueue(Queue* q);

/// <summary>
/// 
/// </summary>
/// <param name="s"></param>
void cutAndReplace(Queue* q);

/// <summary>
/// 
/// </summary>
/// <param name="s"></param>
void sortKidsFirst(Queue* q);

void printQueue(Queue* q);