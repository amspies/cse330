/*****************************************
 * Created by Loi Nguyen & Aidan Spies   *
 * Created for CSE 330 Operating Systems *
 *****************************************/

#ifndef Q_H
#define Q_H

struct node {
	struct node next;
	struct node prev;
	int payload;
};

#endif
