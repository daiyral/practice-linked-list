#include "link_list.h"

void main()
{
	list_manage manager;
	int n;
	manager.head = NULL;
	manager.tail = NULL;
	printf("Enter amount of nodes in linked list:");
	scanf("%d", &n);
	create_link_list(&manager,n);
	print_link_list(&manager);
	//add_to_list(&manager);
	//print_link_list(&manager);
	upper_list(&manager);
	print_link_list(&manager);
	delete_and_free(&manager);
}
