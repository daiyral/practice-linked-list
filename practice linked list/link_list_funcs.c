#include "link_list.h"
/*
create a link list size of n
*/
void create_link_list(Plist manager,int n)
{
	int i;
	node* temp;
	for (i = 0; i < n; i++)
	{
		if (!(temp = (node*)malloc(sizeof(node))))
			free(temp);
		printf("%d.Node value:", i + 1);
		scanf("%d", &temp->num);
		temp->next = manager->head;
		manager->head = temp;
	}
	manager->size = n;
}
/*
add 1 item to link list(only works on a rising list no dups)
*/
void add_to_list(Plist manager)
{
	int flag = 1;
	node* temp;
	manager->prev = manager->head;
	manager->after = manager->head->next;
	if (!(temp = (node*)malloc(sizeof(node))))
		free(temp);
	printf("\nEnter value for node to add:");
	scanf("%d", &temp->num);
	//add to start of list
	if (manager->head->num < temp->num)
	{
		temp->next = manager->head;
		manager->head = temp;
		flag = 0;
	}
	//add to middle of list
	while (manager->prev->next != NULL && flag)
	{
		if (temp->num < manager->prev->num && temp->num >manager->after->num)
		{
			temp->next = manager->after;
			manager->prev->next = temp;
			flag = 0;//we have added the node exit the loop
		}
		manager->prev = manager->prev->next;
		manager->after = manager->after->next;
	}
	//add to end of list
	if (flag)//if we still have not added a node
	{
		manager->prev->next = temp;
		flag = 0;
	}
	manager->size++;
}
/*
free memory
*/
void delete_and_free(Plist manager)
{
	node *temp;
	while (manager->head != NULL)
	{
		temp = manager->head;
		manager->head = manager->head->next;
		free(temp);
	}
}
/*
print the list 
*/
void print_link_list(Plist manager)
{
	int i;
	manager->prev = manager->head;
	for (i = 0; i < manager->size; i++)
	{
		if (i != manager->size - 1)
			printf("%d---->", manager->prev->num);
		else
			printf("%d", manager->prev->num);
		manager->prev = manager->prev->next;

	}
	printf("\n");
}
/*
deletes any node in the list that breaks the rising sequence
DOESNT EXACTLY WORK IF YOU NEED TO DELETE MORE THAN ONCE FIX LATER
*/
/*void upper_list(Plist manager)
{
	int cnt = 0;
	node* temp;
	manager->prev = manager->head;//set prev to the first item in link list
	manager->after = manager->head->next;//set after to be 2 item in link list
	while (manager->after != NULL)
	{
		if (manager->after->num < manager->prev->num)
		{
			temp = manager->after;
			manager->after = manager->after->next;
			manager->prev->next = manager->after;
			free(temp);
			cnt++;//count how many items have been deleted
		}
		manager->prev = manager->prev->next;
		manager->after = manager->after->next;
	}
	manager->size = manager->size - cnt;
}*/


void build_list_tail(Plist manager,int n)
{
	node* temp;
	int i;

	for (i = 0; i < n; i++)
	{
		if (!(temp = (node*)malloc(sizeof(node))))
			free(temp);
		printf("%d.Node value:", i + 1);
		scanf("%d", &temp->num);
		temp->next = NULL;
		if (manager->head == NULL)
			manager->head = temp;
		else
			manager->tail->next = temp;
		manager->tail = temp;

	}
}