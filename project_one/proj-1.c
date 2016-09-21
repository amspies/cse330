/* Created by Loi Nguyen & Aidan Spies */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "q.h"

void error()
{
	puts("ERROR");
}

void check(struct elem *head, int suppose)
{
	int count = 0;
	struct elem *checkQ = head;

	while (checkQ->next->payload != -1) {
		count++;
		checkQ = checkQ->next;
	}

	printf("Suppose number of Item in Queue: %d\n", suppose);
	printf("Item in Queue: %d\n\n", count);
}


int main (int argc, char *argv[])
{
	printf("\nTesting creating Queue and Item\n\n");

	//TEST--Creating new Queue
	struct elem *q1;
	if (q1 == NULL)
		puts("Queue one is empty");
	else
		error();

	//Assigning Queue
	q1 = newQueue();
	if (q1 != NULL)
		puts("Queue one is created");
	else
		error();

	//TEST--Creating Item
	struct elem *item1;
	/*
	if (item1 != NULL) {
		if (item1->next != NULL)
			puts("check");                  //This is not inportant to the code as a whole
		printf("%d", item1->payload);		//But it is interesting how it is not NULL and
		puts("Item one is not empty");		//There is a next
	} else
		error();
	*/
	item1 = newItem();
	if (item1 != NULL && item1->payload == 0)
		puts("item one is created");
	else
		error();

	printf("\nTesting Adding and Deleting Items in Queue\n\n");

	//TEST--addQueue
	addQueue(q1, item1);

	//check Item in queue
	check(q1, 1);

	//TEST--Multiple addQueue
	struct elem *item2 = newItem();
	struct elem *item3 = newItem();

	addQueue(q1, item2);
	addQueue(q1, item3);
	check(q1, 3);


	//TEST--delQueue
	delQueue(q1);					//Same as addQueue
	check(q1, 2);

	//TEST--Multiple delete
	delQueue(q1);
	delQueue(q1);
	check(q1, 0);


	//TEST--Robustness
	printf("\nCheck Robustness\n");
	struct elem *q2 = newQueue();
	struct elem *i1 = newItem();
	struct elem *i2 = newItem();
	struct elem *i3 = newItem();
	struct elem *i4 = newItem();
	struct elem *i5 = newItem();
	struct elem *i6 = newItem();
	struct elem *i7 = newItem();
	struct elem *i8 = newItem();
	struct elem *i9 = newItem();
	struct elem *i10 = newItem();
	struct elem *i11 = newItem();
	struct elem *i12 = newItem();

	check(q2, 0);
	addQueue(q2, i1);
	addQueue(q2, i2);
	addQueue(q2, i3);
	addQueue(q2, i4);
	addQueue(q2, i2); //duplicate. shouldn't be added, so length(q1) does not increase
	addQueue(q2, i5);
	check(q2, 5);

	delQueue(q2);
	delQueue(q2);
	check(q2, 3);


	addQueue(q2, i6);
	delQueue(q2);
	check(q2, 3);

	addQueue(q2, i7);
	addQueue(q2, i8);
	addQueue(q2, i9);
	addQueue(q2, i10);
	addQueue(q2, i11);
	addQueue(q2, i12);
	check(q2, 9);

	delQueue(q2);
	delQueue(q2);
	delQueue(q2);
	delQueue(q2);
	check(q2, 5);
	delQueue(q2);
	delQueue(q2);
	delQueue(q2);
	delQueue(q2);
	delQueue(q2);
	check(q2, 0);


	/* frees memory at address "q1" and assigns it NULL */
	q1 = freeItem(q1);
	if (q1 == NULL)
		puts("Queue one memory is freed");
	else
		error();

	return 0;
}
