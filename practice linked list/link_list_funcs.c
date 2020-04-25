#include "link_list.h"

node* create_link_list(int n)
{
	int i;
	node* head = NULL;
	node* temp;
	for (i = 0; i < n; i++)
	{
		if (!(temp = (node*)malloc(sizeof(node))))
			free(temp);
		printf("%d.Node value:", i + 1);
		scanf("%d", &temp->num);
		temp->next = head;
		head = temp;
	}
	head->length = n;
	return head;

}

void add_to_list(node* head)
{
	int flag = 1;
	node* temp, * prev, * after;
	prev = head;
	after = head->next;
	if (!(temp = (node*)malloc(sizeof(node))))
		free(temp);
	printf("\nEnter value for node to add:");
	scanf("%d", &temp->num);
	//add to start of list
	//NOT WORKING, DOESN'T UPDATE HEAD AFTER FUNCTION ENDS
	if (prev->num < temp->num)
	{
		temp->next = prev;
		head = temp;
		flag = 0;
	}
	//add to middle of list
	while (prev->next != NULL && flag)
	{
		if (temp->num < prev->num && temp->num > after->num)
		{
			temp->next = after;
			prev->next = temp;
			flag = 0;//we have added the node exit the loop
		}
		prev = prev->next;
		after = after->next;
	}
	//add to end of list
	if (flag)//if we still have not added a node
	{
		prev->next = temp;
		flag = 0;
	}
	head->length++;
}
void delete_and_free(node* head)
{

}
void print_link_list(node* head)
{
	int i;
	node* p;
	p = head;
	for (i = 0; i < head->length; i++)
	{
		if (i != head->length - 1)
			printf("%d---->", p->num);
		else
			printf("%d", p->num);
		p = p->next;

	}
}

