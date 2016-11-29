#ifndef Q_H
#define Q_H

#include "tcb.h"

struct TCB_t *newItem();
void newQueue(struct TCB_t **head);
void addQueue(struct TCB_t **head, struct TCB_t *item);
struct TCB_t *delQueue(struct TCB_t **head);
void rotateQueue(struct TCB_t **head);

struct TCB_t *newItem()
{
	return (struct TCB_t *)malloc(sizeof(struct TCB_t));
}

void newQueue(struct TCB_t **head)
{
	if (*head == NULL)
		return;
	else
		*head = NULL;
}

void addQueue(struct TCB_t **head, struct TCB_t *item)
{
	if (head == NULL)
		newQueue(head);

	struct TCB_t *temp = (*head);

	if (temp == NULL) {
		(*head) = item;
		(*head)->next = (*head);
		(*head)->prev = (*head);
	}
	else if (temp->next == temp) {
		(*head)->next = item;
		(*head)->prev = item;
		item->next = (*head);
		item->prev = (*head);
	} else {
		while (temp->next != (*head))
			temp = temp->next;
		item->next = temp->next;
		item->prev = temp;
		temp->next = item;
		(*head)->prev = item;
	}
}

struct TCB_t *delQueue(struct TCB_t **head)
{
	struct TCB_t *item = NULL;

	if (head != NULL) {
		item = (*head);
		if (item == NULL)
			item = NULL;
		else if (item->next == item)
			(*head) = NULL;
		else {
			(*head)->prev->next = (*head)->next;
			(*head)->next->prev = (*head)->prev;
			(*head) = (*head)->next;
		}
	}

	return item;
}

void rotateQueue(struct TCB_t **head)
{
	addQueue(head, delQueue(head));
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

	if (head->next == head)
		printf("\t%p\n", head);
	else {
		struct TCB_t *current = head;
		do {
			printf("\t%p\n", current);
			current = current->next;
		} while (current != head);
	}
}

#endif
