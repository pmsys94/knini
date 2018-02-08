#ifndef KNSLL_H
#define KNSLL_H

#define ver 1.0

	#include <stdio.h>
	#include "knsllnode.h"

	typedef int (*compare_f)(void* key1, void* key2);
	// -------------------   linked list adt   --------------------------------------
	typedef struct list *llist;
	int addItem(llist lst, void *data);
	unsigned int getItemCount(llist lst);
	void* deleteItem(llist lst, void *removeCompData);
	void* searchItem(llist lst, void *searchKey);
	
	llist newlist(compare_f UseToCompare);
	int rmlist(llist lst);
	// -------------------   linked list adt   --------------------------------------

	// -------------------   iterator   ---------------------------------------------
	typedef struct listiterator *literator;
	int hasNext(literator it);
	void* getNext(literator it);
	literator init_it(llist listToIterate);
	void kill_it(literator it);
	// -------------------   iteartor   ---------------------------------------------
#endif
