#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <cstdbool>


typedef struct node {
	int value;
	struct node* next; //pointer to the same type of struct
}Node; //for the typedef just naming


//declaration
void printList(Node* head);
int listLen(Node* head);
Node* insert_at_head(Node* head, int new_value);
Node* insert_at_tail(Node* head, int new_value);
Node* deleteNodeAtHead(Node* head);
Node* deleteNodeAtTail(Node* head);
bool isMember(Node* node, int value);
int searchIndex(Node* head, int value);
int matchCounter(Node* node, int value);
int matchReplace(Node* node, int originalVal, int newVal);
Node* matchDelete(Node* head, int value);

int main() {
	//create the nodes
	Node *n = NULL;

	//testing functions
	
	n = insert_at_head(n, 7);
	n = insert_at_head(n, 5);
	n = insert_at_head(n, 2);
	n = insert_at_head(n, 1);

	n = insert_at_tail(n, 15);
	printList(n);
	printf("\n");

	n = deleteNodeAtHead(n);
	printList(n);
	printf("\n");
	n = deleteNodeAtTail(n);


	n = insert_at_head(n, 53);
	n = insert_at_head(n, 72);
	n = insert_at_head(n, 2);
	n = insert_at_head(n, 54);
	n = insert_at_head(n, 61);
	n = insert_at_head(n, 2);
	printList(n);
	listLen(n);
	if(isMember(n,2))
		searchIndex(n, 2);
	printf("Matches were found: %d\n", matchCounter(n, 2));

	matchReplace(n, 2, 7777);
	printList(n);
	n = matchDelete(n, 7777);
	printList(n);

	free(n);
	return 0;
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

int listLen(Node* head) {
	int i = 0;
	while (head != NULL) {
		
		head = head->next;
		i++;
	}
	printf("The len of the list is: %d\n", i);
	return i;
}

Node* insert_at_head(Node* head, int new_value) {
	Node* new_node = (Node*)calloc(1, sizeof(Node)); // corrected allocation size to sizeof(Node)
	new_node->value = new_value;
	new_node->next = head;
	return new_node;
}

Node* insert_at_tail(Node* head, int new_value) {
	Node* new_node = (Node*)calloc(1, sizeof(Node)); // corrected allocation size to sizeof(Node)
	new_node->value = new_value;

	if (head == NULL)
		return new_node; //return the new list
	else{
		Node* current = head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new_node;
		return head; //return the already existing head
	}
}

Node* deleteNodeAtHead(Node* head) {
	if (head == NULL)
		return NULL;
	else {
		Node* to_return = head->next;
		free(head);
		return to_return;
	}
}

Node* deleteNodeAtTail(Node* head) {
	if (head == NULL)
		return NULL;
	else {
		// If there is only one node in the list
		if (head->next == NULL) {
			free(head);
			return NULL;
		}
		Node* current = head;

		// Traverse the list to find the second to last node
		while (current->next->next != NULL) {
			current = current->next;
		}
		free(current->next); 	// Free the last node

		current->next = NULL; 	// Set the second to last node's next pointer to NULL

		return head;
	}
}

bool isMember(Node* node, int value) {
	if (node == NULL)
		return false;
	else if (node->value == value)
		return true;
	else return isMember(node->next, value);
}

int searchIndex(Node* head, int value) {
	if (head == NULL) {
		return -1; // List is empty
	}
	int i = 0;
	while (head->next != NULL) {
		if (head->value == value)
		{
			printf("The value is in index: %d\n", i);
			return i;
		}

	head = head->next;
	i++;
	}
	
	return -1;

}

int matchCounter(Node* node, int value) {
	if (node == NULL)
		return 0;
	else if (node->value == value)
		return 1+matchCounter(node->next, value); //counts the matches 1+ means that return the found match and all the other matches that might be 
	else return matchCounter(node->next, value);
}

int matchReplace(Node* node, int originalVal, int newVal) {
	if (node == NULL)
		return 0;
	else
		if (node->value == originalVal)
			node->value = newVal;
			
	return matchReplace(node->next, originalVal, newVal);

}

Node* matchDelete(Node* head, int value) {
	if (head == NULL)
		return head;

	// Handle cases where the head node contains the value
	while (head != NULL && head->value == value) {
		Node* temp = head;
		head = head->next;
		free(temp);
	}

	// If list becomes empty after removing matching head nodes
	if (head == NULL) {
		return head;
	}

	Node* current = head;
	// Traverse the list to find the second to last node
	while (current != NULL && current->next != NULL) {
		if (current->next->value == value) {
			Node* temp = current->next;
			current->next = current->next->next; //assign the next next to the current link
			free(temp); //free the next link
		}
		else {
			current = current->next;
		}

	}
	return head;
}
