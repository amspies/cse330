#ifndef SEM_H
#define SEM_H

#include "threads.h"

typedef struct semaphore {
	int value;
	struct TCB_t **queue;
} semaphore;

void newSemaphore(semaphore *sem, int value)
{
	sem->value = value;
}

void wait(semaphore *sem)
{
	sem->value--;
	if (sem->value < 0)
	// Curr_Thread gets added to sem->queue
	// New thread selected from ReadyQ and put in Curr_Thread
	// swapcontext
}

void signal(semaphore *sem)
{

}


#endif
