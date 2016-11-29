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
	newQueue(&(sem->queue));
}

void P(struct semaphore *sem)
{
	sem->value--;
	if (sem->value < 0) {
		struct TCB_t *blockedQ = runQ;
		struct TCB_t *currThread = delQueue(&runQ);
		addQueue(&(sem->queue), blockedQ);
		swapcontext(&(blockedQ->context), &(runQ->context));
	}
}

void V(struct semaphore *sem)
{
	sem->value++;
	if (sem->value <= 0 && sem->queue != NULL) {
		addQueue(&runQ, delQueue(&(sem->queue)));
		yield();
	}
}

#endif
