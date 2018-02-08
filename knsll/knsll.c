#include "knsll.h"

struct list{
	unsigned int items;
	lnode first;
	lnode last;
	compare_f compFunc;
};

struct listiterator{
	llist list;
	lnode current;
};

// -------------------   linked list adt   --------------------------------------

int addItem(llist lst, void *data){
	if(lst == NULL) return 0;
	lnode nd = newnode(data);
	if (nd == NULL) return 0;
	if (lst->first == NULL){
		lst->first = nd;
	} else {
		lst->last->setNext(nd);
	}	
	lst->last = nd;
	(lst->items)++;
	return 1;
}

unsigned int getItemCount(llist lst){
	if(lst == NULL) return 0;
	return lst->items;
}

void* deleteItem(llist lst, void *removeCompData){
	void* rmdata = NULL;
	if(lst == NULL) return rmdata;// returns NULL
	if (lst->items == 0) return rmdata; // returns NULL
	lnode last = NULL;
	lnode node = lst->first;
	while(node != NULL){
		int comp = lst->compFunc(removeCompData, node->getData());
		if(comp == 0){ //found
			if(last == NULL){// first item should be deleted
				lst->first = node->getNext();
			} else {
				last->setNext(node->getNext());// if this is the last node: get Next returns NULL and NULL will be set on the previous node as next
			}
			node->setNext(NULL); // prevent recursive delete
			rmdata = node->getData();
			rmnode(node);
			node = NULL;
			(lst->items)--;
		} else { // not found
			last = node;
			node = node->getNext();
		}
	}
	return rmdata;
}

void* searchItem(llist lst, void *searchKey){
	if(lst == NULL) return NULL;
	if (lst->items == 0) return NULL;
	lnode node = lst->first;
	while(node != NULL){
		int comp = lst->compFunc(searchKey, node->getData());
		if(comp == 0){ //found
			return node->getData();
		} else { // not found
			node = node->getNext();
		}
	}
	return NULL;
}
		
llist newlist(compare_f UseToCompare){
	if(UseToCompare == NULL) return NULL;
	llist lst = (llist)malloc(sizeof(*llist));
	if(lst == NULL) return NULL;
	lst->items = 0;
	lst->first = NULL;
	lst->compFunc = UseToCompare;
	return lst;
}

int rmlist(llist lst){
	if(lst == NULL) return 1;
	if(lst->items > 0){
		rmnode(lst->first);
	}
	free(lst);
	return 1;
}
// -------------------   linked list adt   --------------------------------------

// -------------------   iterator   ---------------------------------------------

int hasNext(literator it){
	if(it == NULL) return 0;
	return it->current->getNext();
}

void* getNext(literator it){
	if(it == NULL) return NULL;
	if(it->list == NULL) return NULL;
	if(it->hasNext() == 0) return NULL;
	lnode node = it->current;
	it->current = it->current->getNext();
	return node->getData();
}

literator init_it(llist listToIterate){
	if(listToIterate == NULL) return NULL;
	literator it = (literator)malloc(sizeof(*literator));
	if(it == NULL) return NULL;
	it->list = listToIterate;
	it->current = it->list->first;
	return it;
}

void kill_it(literator it){
	if(it == NULL) return;
	free(it);
}
// -------------------   iteartor   --------------------------------------------
