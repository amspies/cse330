#ifndef TCB_H
#define TCB_H

#include <ucontext.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

struct TCB_t {
     struct TCB_t *next;
     struct TCB_t *prev;
     ucontext_t context;
};

void init_TCB(struct TCB_t *tcb, void (*function)(void), void *stack, int stack_size)
{
    memset(tcb, '\0', sizeof(struct TCB_t));       // wash, rinse
    getcontext(&tcb->context);              // have to get parent context, else snow forms on hell
    tcb->context.uc_stack.ss_sp = stack;
    tcb->context.uc_stack.ss_size = (size_t) stack_size;
    makecontext(&tcb->context, function, 0);// context is now cooked
}

#endif
