/* Created by Loi Nguyen & Aidan Spies */

#ifndef Q_H
#define Q_H

struct elem {
	struct elem *next;
	struct elem *prev;
	int payload;
};


struct elem *newItem()
{
	struct elem *newElement = malloc(sizeof(struct elem));
	newElement->payload = 0;
	return newElement;
}

struct elem *newQueue()
{
	struct elem *newElement = newItem();
	newElement->next = newElement;
	newElement->prev = newElement;
	newElement->payload = -1;
}

struct elem *addQueue(struct elem *head, struct elem *item)
{
	if (item == NULL)
		item = newItem();

	struct elem *temp = head;

	while (temp->next->payload != -1)
		temp = temp->next;

	item->prev = temp;
	temp->next = item;
	item->next = head;
	head->prev = item;
}


struct elem *delQueue(struct elem *head)
{
	struct elem *temp = NULL;

	if (head->next->payload != -1) {
		temp = head->next;
		head->next->next->prev = head;
		head->next = head->next->next;
	}

	return temp;
}

void freeItem(struct elem *toDelete)
{
	delete(toDelete);
}

#endif
