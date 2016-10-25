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
	TCB_t *temp = *head;
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
	TCB_t *del = *head;
	if (del->next == del) {
		*head = NULL;
	} else {
		while (del->next != *head) {
			del = del->next;
		}
		del->prev->next = del->next;
		del->next->prev = del->prev;
	}

	return del;
}

void rotateQueue(struct TCB_t **head)
{
	if (head != NULL) {
		TCB_t* temp = *head;
		*head = temp->next;
	}
}

void freeItem(void *item)
{
	free(item);
}

void printQueue(struct TCB_t *headPtr)
{
	if (headPtr == NULL) {
		puts("queue head is null");
		return;
	}

	if (headPtr->next == headPtr) {
		printf("\t%p\n", headPtr);
	} else {
		TCB_t *current = headPtr;
		do {
			printf("\t%p\n", current);
			current = current->next;
		} while (current != headPtr);
	}
}

#endif
