/* Created by Loi Nguyen & Aidan Spies */

#ifndef Q_H
#define Q_H

#include "tcb.h"

void newQueue(struct TCB_t **head)
{
	*head = NULL;
}

struct TCB_t *newItem()
{
	return (struct TCB_t *)malloc(sizeof(struct TCB_t));
}

void addQueue(struct TCB_t **head, struct TCB_t *item)
{
	struct TCB_t *temp = *head;
	if (temp == NULL) {
		*head = item;
		(*head)->next = *head;
		(*head)->prev = *head;
	} else if (temp->next == temp) {
		temp->next = item;
		temp->prev = item;
		item->next = temp;
		item->prev = temp;
	} else {
		while (temp->next != *head)
			temp = temp->next;
		item->next = temp->next;
		item->prev = temp;
		temp->next = item;
		(*head)->prev = item;
	}
}

struct TCB_t *delQueue(struct TCB_t **head)
{
	struct TCB_t *item = *head;
	if (item->next == item) {
		*head = NULL;
	} else {
		while (item->next != *head) {
			item = item->next;
		}
		item->prev->next = item->next;
		item->next->prev = item->prev;
	}

	return item;
}

struct TCB_t *rotateQueue(struct TCB_t **head)
{
	struct TCB_t *temp = NULL;
	if (head != NULL) {
		temp = *head;
		*head = temp->next;
	}

	return temp;
}

void freeItem(void *item)
{
	free(item);
}

void printQueue(struct TCB_t *head)
{
	if (head == NULL) {
		puts("queue head is null");
		return;
	}

	if (head->next == head) {
		printf("\t%p\n", head);
	} else {
		struct TCB_t *current = head;
		do {
			printf("\t%p\n", current);
			current = current->next;
		} while (current != head);
	}
}

#endif
