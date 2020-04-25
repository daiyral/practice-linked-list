#include "link_list.h"

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
	manager->size++;//THIS DOESNT WORK
}
void delete_and_free(Plist manager)
{

}
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
}

