/* Created by Loi Nguyen and Aidan Spies */

#include "sem.h"
#define BUFFER_SIZE 3
#define NUM_THREADS 3

struct TCB_t *runQ = NULL;
struct semaphore *full = NULL, *empty = NULL;

int buffer[BUFFER_SIZE];
int in = 0, out = 0;

void producer()
{
	while (1) {
		P(full);
		buffer[in] = rand();
		printf("%p produced %d at %d\n", runQ, buffer[in], in);
		sleep(1);
		in = (in + 1) % BUFFER_SIZE;
		V(empty);
	}
}

void consumer()
{
	while(1) {
		P(empty);
		printf("%p consumed %d at %d\n", runQ, buffer[out], out);
		sleep(1);
		out = (out + 1) % BUFFER_SIZE;
		V(full);
	}
}


int main()
{
	struct TCB_t *threads[NUM_THREADS];
	puts("Creating threads and semaphores...");

	full = (struct semaphore *)malloc(sizeof(struct semaphore));
	empty = (struct semaphore *)malloc(sizeof(struct semaphore));

	newSemaphore(empty, 0);
	newSemaphore(full, BUFFER_SIZE);

	newQueue(&runQ);

	int i;
	for (i = 0; i < NUM_THREADS; i++) {
		if (i >= 2)
			startThread(threads[i], producer);
		else
			startThread(threads[i], consumer);
	}

	srand((unsigned) time(NULL));
	puts("runQ content:");
	printQueue(runQ);
	puts("\nstarting threads\n");
	run();

	return 0;
}
