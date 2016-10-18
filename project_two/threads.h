#ifndef THREADS_H
#define THREADS_H
#include "TCB_t.h"

struct TCB_t *ReadyQ;
struct TCB_t *Curr_Thread;

void start_thread(struct TCB_t *tcb, oid (*function)(void))
{ // begin pseudo code
     	//allocate a stack (via malloc) of a certain size (choose 8192)
	void *stackP = malloc(8192);
     	//allocate a TCB (via malloc)
	tcb = malloc(sizeof(struct TCB_t)); 
     	//call init_TCB with appropriate arguments
	init_TCB(tcb, fuction, stackP, 8192);
     	//call addQ to add this TCB into the “ReadyQ” which is a global header pointer
	AddQueue(&ReadyQ,tcb)
  //end pseudo code
}


void run()
{   	// real code
    	Curr_Thread = DelQueue(ReadyQ)
    	ucontext_t parent;     // get a place to store the main context, for faking
    	getcontext(&parent);   // magic sauce
    	swapcontext(&parent, &(Curr_Thread->context));  // start the first thread
} 
void yield() // similar to run
{ 	// begin pseudo code
   	AddQueue(Ready_Q, Curr_Thread); 
   	Prev_Thread = Curr_Thread;
   	Curr_Thread = DelQueue(ReadyQ);
   	//swap the context, from Prev_Thread to the thread pointed to Curr_Thread
     	swapcontext(&(Prev_Thread->context), &(Curr_Thread->context)); //Check this for correction, I feel like I swapped the variable
	// end pseudo code
}

#endif
