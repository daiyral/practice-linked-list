#include "link_list.h"

void main()
{
	node* head = NULL;
	int n;
	printf("Enter amount of nodes in linked list:");
	scanf("%d", &n);
	head=create_link_list(n);
	print_link_list(head);
	add_to_list(head);
	print_link_list(head);
}
