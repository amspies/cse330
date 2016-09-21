/* Created by Loi Nguyen & Aidan Spies */

#include <stdlib.h>
#include <stdio.h>
#include "q.h"

void error(){
	puts("ERROR");
}

void check(struct elem *head, int suppose){
	int count = 0;
	struct elem *checkQ = head;
	while (checkQ->next->payload != -1){
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
	if (item1 != NULL){
		if (item1->next != NULL)	
			puts("check");                  //This is not inportant to the code as a whole
		printf("%d", item1->payload);		//But it is interesting how it is not NULL and 
		puts("Item one is not empty");		//There is a next 
	}
	else
		error();
	*/
	item1 = newItem();
	if (item1 != NULL && item1->payload == 0)
		puts("item one is created");
	else
		error();
	
	printf("\nTesting Adding and Deleting Items in Queue\n\n");
	
	//TEST--addQueue
	addQueue(q1, item1);				//Dont need a return since the head is already 
							//Rewritten in the function
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
	//addQueue(q2, i2);			//We dont have a check duplicates
	addQueue(q2, i5);			//Not sure if it is required but it a good idea
	check(q2, 5);
	
	delQueue(q2);
	delQueue(q2);
	check(q2, 3);
	
	/*
	addQueue(q2, i5);			//Use this to test if we do decide to test for 
	check(q2, 4);				// Duplicates
	delQueue(q2);
	check(q2, 3);
	*/

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

	/*
	fr(q1);
	if (q1 != NULL){
		printf("%d", q1->payload);
		puts("Queue one memory is freed");
	}
	else 
		error();


	struct elem *q1 = newQueue();
	puts("Queue One created");
	struct elem *q2 = newQueue();
	puts("Queue Two created\n");

	



	freeItem(q1);
	puts("Queue One memory freed");
	freeItem(q2);
	puts("Queue Two memory freed");
	*/
	return 0;
}
