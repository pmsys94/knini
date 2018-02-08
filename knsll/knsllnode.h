#ifndef KNSLLNODE_H
#define KNSLLNODE_H

#define ver 1.0

	#include <stdio.h>
	typedef struct listnode *lnode;

	void* getData(lnode nd);
	void setNext(lnode nd, lnode toLink);
	lnode getNext(lnode nd);
	lnode newnode(void *toSave);
	int rmnode(lnode nd);

#endif
