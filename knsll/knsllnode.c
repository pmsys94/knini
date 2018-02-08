#include "knsllnode.h"

struct listnode{
	void* data;
	lnode next;
};

void* getData(lnode nd){
	if(nd == NULL) return NULL;
	return nd->data;
}

lnode newnode(void *toSave){
	lnode nd = (lnode)malloc(sizeof(*lnode));
	if (nd == NULL) return NULL;
	nd->data = toSave;
	nd->next = NULL;
	return nd;
}

int rmnode(lnode nd){
	if (nd == NULL) return 0;
	if(nd->next != NULL){
		rmnode(nd->next);
	}
	free(nd);
	return 1;
}

void setNext(lnode nd, lnode toLink){
	if(nd == NULL) return;
	nd->next = toLink;
}

lnode getNext(lnode nd){
	if(nd == NULL) return NULL;
	return nd->next;
}
