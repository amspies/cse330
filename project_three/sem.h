#ifndef SEM_H
#define SEM_H

#include "threads.h"

struct semaphore {
	int value;
	struct TCB_t *queue;
};

void newSemaphore(struct semaphore *sem, int value)
{
	sem->value = value;
}

void P(struct semaphore *sem)
{
	sem->value--;
	if (sem->value < 0) {
		//rotateQueue(&runQ);
		struct TCB_t *currThread = delQueue(&runQ);
		addQueue(&(sem->queue), currThread);
		while (runQ == NULL) ;
		swapcontext(&(currThread->context), &(runQ->context));
	}
}

void V(struct semaphore *sem)
{
	sem->value++;
	if (sem->value <= 0 && sem->queue != NULL) {
		//rotateQueue(&runQ);
		addQueue(&runQ, delQueue(&(sem->queue)));
	}
	yield();
}


#endif
