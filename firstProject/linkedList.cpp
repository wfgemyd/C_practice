#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



typedef struct node {
	int value;
	struct node* next; //pointer to the same type of struct
}Node; //for the typedef just naming


//declaration
void printList(Node* head);
void addToList(Node* head);

int main() {
	//create the nodes
	Node a, b, c;


	//initialize values
	a.value = 5;
	b.value = 3;
	c.value = 8;

	//initialize pointes
	a.next = &b;
	b.next = &c;
	c.next = NULL;

	//testing functions
	printList(&a);
	addToList(&a);
}

void printList(Node* head) {
	Node* current;
	current = head; //copying\assigning the pointer (address)
	int i = 0;
	while (current != NULL) {
		printf("Node %d: %d\n", i, current->value);
		current = current->next;
		i++;
	}
}

void addToHeadList(Node* head) {
	Node* current;
	current = head;
	int i = 0;
	if (current != NULL) {
		Node* newNode;
	}
}