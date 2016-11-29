#ifndef THREADS_H
#define THREADS_H

#include "q.h"

extern struct TCB_t *runQ;

void startThread(struct TCB_t *thread, void (*function)(void))
{
	void *stack = (void *)malloc(8192);
	thread = newItem();
	init_TCB(thread, function, stack, 8192);
	addQueue(&runQ, thread);
}

void run()
{
	ucontext_t parent;
	getcontext(&parent);
	swapcontext(&parent, &(runQ->context));
}

void yield()
{
	struct TCB_t *prev = runQ;
	rotateQueue(&runQ);
	swapcontext(&(prev->context), &(runQ->context));
}

#endif
