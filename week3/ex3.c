#include <stdio.h>

struct node {
	int data;
	struct node* next;
};

struct linked_list
{
	struct node* head;
};

void print_list(struct linked_list* list) {
	struct node* current = list->head->next;
	while (current) {
		printf("%i ", current->data);
		current = current->next;
	}
	printf("\n");
}

void insert_node(struct linked_list* list, int new_data, int index) {
	struct node* current = list->head;
	for(int i = 0; i < index; ++i)
		current = current->next;
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = new_data;
	new_node->next = current->next;
	current->next = new_node;
}

void delete_node(struct linked_list* list, int index) {
	struct node* current = list->head;
	for(int i = 0; i < index; ++i)
		current = current->next;
	struct node* node_to_be_deleted = current->next;
	current->next = current->next->next;
	free(node_to_be_deleted);
}

int main() {
	struct linked_list* my_linked_list = (struct linked_list*)malloc(sizeof(struct linked_list));
	my_linked_list->head = (struct node*)malloc(sizeof(struct node));
	my_linked_list->head->next = NULL; 
	insert_node(my_linked_list, 5, 0);
	print_list(my_linked_list);
	insert_node(my_linked_list, 7, 0);
	print_list(my_linked_list);
	insert_node(my_linked_list, 8, 2);
	print_list(my_linked_list);
	delete_node(my_linked_list, 1);
	print_list(my_linked_list);
	insert_node(my_linked_list, -1, 1);
	print_list(my_linked_list);
	return 0;
}