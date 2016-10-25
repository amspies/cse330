/* Written by Aidan Spies & Loi Nguyen */

#include "threads.h"

#define NUM_THREADS 3

struct TCB_t *runQ = NULL;
int global = 0;


void test1()
{
	int i = 0;
	while (global >= 0) {
		printf("test1 = Swapped %d : CurrentThread %p : Visited %d \n", global, runQ, ++i);
		global++;
		sleep(1);
		puts("test1 - swapping");
		yield();
		puts("test1 - post yield");
	}
}

void test2()
{
	int x = 0;
	while (global >= 0) {
		printf("test2 = Swapped %d : CurrentThread %p : Visited %d \n", global, runQ, ++x);
		global++;
		sleep(1);
		puts("test2 - swapping");
		yield();
		puts("test2 - post yield");
	}
}

int main()
{
	struct TCB_t *threads[NUM_THREADS];

	printf("Initializing %d threads\n", NUM_THREADS);
	newQueue(&runQ);

	int i;
	for (i = 0; i < NUM_THREADS; i++)
		startThread(threads[i], (i % 2 == 0) ? test1 : test2);

	puts("runQ content: ");
	printQueue(runQ);
	puts("\nStarting threads\n");

	run();

	puts("Run ended");
}
