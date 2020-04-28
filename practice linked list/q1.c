#include "link_list.h"

void main()
{
	list_manage manager;
	int n;
	manager.head = NULL;
	manager.tail = NULL;
	printf("Enter amount of nodes in linked list:");
	scanf("%d", &n);
	build_list_tail(&manager,n);
	print_link_list(&manager);
	print_link_list(&manager);
	delete_and_free(&manager);
}

