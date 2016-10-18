/* Created by Loi Nguyen & Aidan Spies */

#ifndef Q_H
#define Q_H

#include "tcb.h"

//Updated all the functions so that it can use tcb.h

struct TCB_t *newItem()
{
	struct TCB_t *newElement = malloc(sizeof(struct TCB_t));
	return newElement;
}

struct TCB_t *newQueue(TCB_t **head)
{
	//assuming that we will make a new TCB in the main
	head = NULL;
}

struct TCB_t *addQueue(struct TCB_t **head, struct TCB_t *item)
{	
	struct TCB_t *temp = *head;
	//For head when it's empty
	if (temp == NULL)
	}
		*head = item;
		(*head)->next = *head;
		(*head)->next = *head;
	}
	//For head when it have one element
	else if (temp->next == temp)
	{
		temp->next = item;
		temp->prev = item;
		item->next = temp;
		item->prev = temp;
	}
	//For head when it has more than one elements
	else
	{
		while( temp->next != *head)
		{
			temp = temp->next;
		}
		item->next = temp->next;
		item->prev = temp;
		temp->next = item;
		(*head)->prev = item;
	}
}


struct TCB_t *delQueue(struct TCB_t **head)
{
	struct TCB_t *temp = *head;
	if (temp->next = temp) 
	{
		*head = NULL;
	else
	{	while (temp->next != *head)
		{
			temp = temp->next;
		}	
		//temp->prev->next = *head;
		temp->prev->next = temp->next;
		//(*head)->prev = temp->prev; 
		temp->next->prev = temp->prev;
		//These two line is more flexable
	}

	return temp;
}

void freeItem(struct TCB_t **toDelete)
{
	free(*toDelete);
}

#endif
