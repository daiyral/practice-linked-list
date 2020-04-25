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
	int length;
	struct node* next;
}node;
node* create_link_list(int n);//create link list
void add_to_list(node* head);//add 1 node to list
void print_link_list(node* head);//print list
void delete_and_free(node* head);
void upper_list(node* head);//didnt do yet 

#endif