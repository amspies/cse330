
#include <ucontext.h>
// This is given to us
typedef struct TCB_t {
     struct TCB_t     *next;
     struct TCB_t     *prev;
     ucontext_t      context;
     int thread_id;
} TCB_t;

int global_thread_id = 0;

void init_TCB (TCB_t *tcb, void (*function) (void), void *stackP, int stack_size)
{
    memset(tcb, '\0', sizeof(TCB_t));       // wash, rinse
    getcontext(&tcb->context);              // have to get parent context, else snow forms on hell
    tcb->context.uc_stack.ss_sp = stackP;
    tcb->context.uc_stack.ss_size = (size_t) stack_size;
    tcb->thread_id = global_thread_id ++;
    makecontext(&tcb->context, function, 0);// context is now cooked
}


