#include <stdio.h>

struct node {
	int data;
	struct node *next, *prev;
};

struct linked_list
{
	struct node *head, *tail;
};

struct node* create_node(int data, struct node* next, struct node* prev) {
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = next;
	new_node->prev = prev;
	return new_node;
}

struct linked_list* create_linked_list() {
	struct linked_list* new_linked_list = (struct linked_list*)malloc(sizeof(struct linked_list));
	new_linked_list->head = create_node(0, NULL, NULL);
	new_linked_list->tail = create_node(0, NULL, new_linked_list->head);
	new_linked_list->head->next = new_linked_list->tail;
	return new_linked_list;
}

void print_list(struct linked_list* list) {
	struct node* current = list->head->next;
	printf("head <-> ");
	while (current != list->tail) {
		printf("%i <-> ", current->data);
		current = current->next;
	}
	printf("tail\n");
}

void insert_node(struct linked_list* list, int new_data, int index) {
	struct node* current = list->head;
	for(int i = 0; i < index; ++i)
		current = current->next;
	struct node* new_node = create_node(new_data, current->next, current);
	current->next = new_node;
	new_node->next->prev = new_node;
}

void delete_node(struct linked_list* list, int index) {
	struct node* current = list->head;
	for(int i = 0; i < index; ++i)
		current = current->next;
	struct node* node_to_be_deleted = current->next;
	current->next = current->next->next;
	current->next->prev = current;
	free(node_to_be_deleted);
}

int main() {
	struct linked_list* my_linked_list = create_linked_list();
	print_list(my_linked_list);
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