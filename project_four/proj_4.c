/* Created by Loi Nguyen and Aidan Spies */

#include "sem.h"
#define NUM_THREADS 4

struct TCB_t *runQ = NULL;
struct semaphore *s0 = NULL, *s1 = NULL, *s2 = NULL, *s3 = NULL;

int array[3] = {0, 0, 0};

/* Option One: Semaphores */
void parent()
{
	while (1) {
		P(s3);
		printf("[ %d %d %d ]\n", array[0], array[1], array[2]);
		sleep(1);
		V(s0); V(s1); V(s2);
	}
}

void c0()
{
	while(1) {
		P(s0);
		array[0]++;
		sleep(1);
		V(s3);
	}
}

void c1()
{
	while(1) {
		P(s1);
		array[1]++;
		sleep(1);
		V(s3);
	}
}

void c2()
{
	while(1) {
		P(s2);
		array[2]++;
		sleep(1);
		V(s3);
	}
}

/* Option Two: "N" Threads */





int main(int argc, char *argv[])
{
	struct TCB_t *threads[NUM_THREADS];
	puts("Creating threads and semaphores...");

	s0 = (struct semaphore *)malloc(sizeof(struct semaphore));
	s1 = (struct semaphore *)malloc(sizeof(struct semaphore));
	s2 = (struct semaphore *)malloc(sizeof(struct semaphore));
	s3 = (struct semaphore *)malloc(sizeof(struct semaphore));

	newSemaphore(s0, 0);
	newSemaphore(s1, 0);
	newSemaphore(s2, 0);
	newSemaphore(s3, 3);

	newQueue(&runQ);

	int i;
	for (i = 0; i < NUM_THREADS; i++) {
		if (i == 3)
			startThread(threads[i], parent);
		else if (i == 2)
			startThread(threads[i], c2);
		else if (i == 1)
			startThread(threads[i], c1);
		else if (i == 0)
			startThread(threads[i], c0);
	}

	srand((unsigned)time(NULL));
	puts("\nstarting threads\n");
	run();

	return 0;
}
