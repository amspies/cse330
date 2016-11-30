/* Created by Loi Nguyen and Aidan Spies */

#include "sem.h"
#define NUM_THREADS 4

struct TCB_t *runQ = NULL;
struct semaphore *s0 = NULL, *s1 = NULL, *s2 = NULL, *s3 = NULL;
int op_one[3] = {0, 0, 0};

struct semaphore **s;
int num_threads;
int num_children;
int parent_index;
int child_index = -1;
int *op_two;

void parent1();
void c0(); void c1(); void c2();

void parent();
void child();

void optionone();
void optiontwo();

int main(int argc, char *argv[])
{
	/* initializes the queue where the TCBs are stored. global variable. */
	newQueue(&runQ);

	/* Option One: 1 Parent and 3 Children */
	//optionone();

	/* Option Two: 1 Parent and N Children */
	optiontwo();

	return 0;
}

/*****************************************************************************************/
/************************** Option Two: 1 Parent and N Children **************************/
/*****************************************************************************************/

void optiontwo()
{
	/* asking for number of children */
	printf("How many children? ");
	scanf("%d", &num_children);

	/* increase by 1 to add parent to the list */
	num_threads = num_children + 1;
	parent_index = num_children;

	puts("\nCreating threads and semaphores...");

	/* creates the threads for the children and parent to live in */
	struct TCB_t *threads[num_threads];

	/* initializes the array for the semaphores. currently, N+1 semaphores */
	s = (struct semaphore **)malloc(sizeof(struct semaphore *)*num_threads);

	/* creates the array that the children will work on */
	op_two = (int *)malloc(sizeof(int)*(num_children));

	/* fills the array with 0s */
	bzero(op_two, num_children);

	/* initializes semaphores for children. currently, N semaphores */
	int i;
	for(i = 0; i < num_children; i++) {
		s[i] = (struct semaphore *)malloc(sizeof(struct semaphore));
		newSemaphore(s[i], 0);
	}

	/* initializes semaphore for parent */
	s[parent_index] = (struct semaphore *)malloc(sizeof(struct semaphore));
	newSemaphore(s[parent_index], num_children);

	/* populates threads with children and parent */
	for (i = 0; i < num_children; i++) startThread(threads[i], child);
	startThread(threads[parent_index], parent);

	srand((unsigned)time(NULL));
	puts("\nstarting threads\n");

	run();
}

void parent()
{
	while (1) {
		int i;
		P(s[parent_index]);
		printf("[ ");
		for (i = 0; i < num_children; i++) printf("%d ", op_two[i]);
		printf("]\n");
		sleep(1);
		child_index = -1;
		for (i = 0; i < num_children; i++) V(s[i]);
	}
}

void child()
{
	while(1) {
		child_index++;
		P(s[child_index]);
		op_two[child_index]++;
		V(s[parent_index]);
	}
}

/*****************************************************************************************/
/************************** Option One: 1 Parent and 3 Children **************************/
/*****************************************************************************************/

void optionone()
{
	/* Option One: 1 Parent and 3 Children */

	/* creates the threads for the children and parent to live in */
	struct TCB_t *threads[NUM_THREADS];
	puts("Creating threads and semaphores...");

	s0 = (struct semaphore *)malloc(sizeof(struct semaphore));
	s1 = (struct semaphore *)malloc(sizeof(struct semaphore));
	s2 = (struct semaphore *)malloc(sizeof(struct semaphore));
	s3 = (struct semaphore *)malloc(sizeof(struct semaphore));

	/* initializes semaphores for 3 children, 1 parent. */
	newSemaphore(s0, 0);
	newSemaphore(s1, 0);
	newSemaphore(s2, 0);
	newSemaphore(s3, 3);

	int i;
	for (i = 0; i < NUM_THREADS; i++) {
		if (i == 0)
			startThread(threads[i], c0);
		else if (i == 1)
			startThread(threads[i], c1);
		else if (i == 2)
			startThread(threads[i], c2);
		else
			startThread(threads[i], parent1);
	}

	srand((unsigned)time(NULL));
	puts("\nstarting threads\n");

	run();
}

void parent1()
{
	while (1) {
		P(s3);
		printf("[ %d %d %d ]\n", op_one[0], op_one[1], op_one[2]);
		sleep(1);
		V(s0); V(s1); V(s2);
	}
}

void c0()
{
	while(1) {
		P(s0);
		op_one[0]++;
		sleep(1);
		V(s3);
	}
}

void c1()
{
	while(1) {
		P(s1);
		op_one[1]++;
		sleep(1);
		V(s3);
	}
}

void c2()
{
	while(1) {
		P(s2);
		op_one[2]++;
		sleep(1);
		V(s3);
	}
}
