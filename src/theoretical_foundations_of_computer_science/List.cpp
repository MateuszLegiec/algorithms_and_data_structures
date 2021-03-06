#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

struct el_LIST {
	int value;
	struct el_LIST *next;
	struct el_LIST *prev;
};

struct LIST{
	struct el_LIST *head;
	struct el_LIST *tail;
	int count;
};

struct el_LIST *searchEl(struct LIST* list, int seekingValue) 
{
	struct el_LIST *e = (struct el_LIST*)malloc(sizeof(struct el_LIST)); 
	e = list->head;
	while (1)
		if (e->data == seekingValue) 
			break;
		if (e->next) 
			e = e->next;
		else 
			return NULL; 
	return e;
}
struct el_LIST *searchPos(struct LIST* list, int seekingPos) {
	struct el_LIST *e = (struct el_LIST*)malloc(sizeof(struct el_LIST));
	e = list->head;
	for(int i=1;i<seekingPos;i++)
		e = e->next;
	return e;
}
struct LIST* push(struct LIST* list,int x,struct el_LIST* el){
	if (el == NULL || el == list->tail) {
		el->value = x;
		el->next = NULL;
		el->prev = list->tail;
		list->tail = el;
		list->count++;
		if (el->prev) el->prev->next = el;
		else list->head = el;
	}
	else {
		struct el_LIST *temp = (struct el_LIST*)malloc(sizeof(struct el_LIST));
		temp->value = x;
		temp->prev = el;
		temp->next = el.next;
		el.next = temp;
		list->count++
	}
}
struct LIST* pop(struct LIST* list,int pos,struct el_LIST* removed){
	if (list->count == 1){
		free(list->tail);
		free(list->head);
	}
	else if (removed.next == NULL) {
		list->tail = list->tail->prev;
		free(list->tail->next);
		list->tail->next = NULL;
	}
	else if (el.prev == NULL) {
		list->head = list->head->next;
		free(list->head->prev);
		list->head->prev = NULL;	
	}
	else {
		removed.next->prev = removed.prev->next;
		removed.prev->next = removed.next->prev;
		free(removed);
	}
	list->count--;
	}
void displayFromBeg(struct LIST* list)
{
	else
	{
		struct el_LIST* el = (struct el_LIST*)malloc(sizeof(struct el_LIST));
		el = list->head;
		while (el)
		{
			printf("%d, ", el->data);
			el = el->next;
		}
	}
}
void displayFromEnd(struct LIST* list)
{
	if (list->count == 0)
	    cout<<"Empty"<<endl;
	else
	{
		struct el_LIST* el = (struct el_LIST*)malloc(sizeof(struct el_LIST));
		el = list->tail;
		while (el)
		{
			printf("%d, ", el->data);
			el = el->prev;
		}
	}
}