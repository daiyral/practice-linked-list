#ifndef _link_list
#define _link_list

/*
Header file for link list funcs to create,remove and add items.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
	int num;
	struct node* next;
}node;

typedef struct list_manage
{
	node* head;
	node* tail;
	node* prev;
	node* after;
	int size;
}list_manage,*Plist;
void create_link_list(Plist manager,int n);//create link list
void add_to_list(Plist manager);//add 1 node to list
void print_link_list(Plist manager);//print list
void delete_and_free(Plist manager);
void upper_list(Plist manager);//didnt do yet 

#endif