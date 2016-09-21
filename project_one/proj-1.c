/* Created by Loi Nguyen & Aidan Spies */

#include <stdlib.h>
#include <stdio.h>
#include "q.h"

int main (int argc, char *argv[])
{
	struct elem *q1 = newQueue();
	puts("Queue One created");
	struct elem *q2 = newQueue();
	puts("Queue Two created\n");





	freeItem(q1);
	puts("Queue One memory freed");
	freeItem(q2);
	puts("Queue Two memory freed");

	return 0;
}
