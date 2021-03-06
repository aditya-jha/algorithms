/*
	Singly Linked List
	C Implementation
	Aditya Jha
*/

#include<stdio.h>
#include<stdlib.h>

//Declation
typedef struct node *node_ptr;

struct node {
	int         data;
	node_ptr    next;
};

typedef node_ptr position;
typedef node_ptr LIST;

//Function to test if LIST is_empty()
int is_empty(LIST L) {
	return (L->next == NULL);
}

//Function to test if the given element is the last_element()
int is_last(position p) {
	return (p->next == NULL);
}

//Function to find a particulat element
position find(int x, LIST L) {
	position p = L->next;
	
	while((p->next != NULL) && (p->data != x))
		p = p->next;
		
	return p;
}

//Function to find_previous
position find_previous(int x, LIST L) {
	position p;
	p = L;
	
	while((p->next != NULL) && (p->next->data != x))
		p = p->next;
	
	return p;
}

//Function to delete an element
void delete(int x, LIST L) {
	position p, temp_cell;
	
	p = find_previous(x,L);
	
	if(p->next != NULL) {
		temp_cell = p->next;
		p->next = temp_cell->next;
		free(temp_cell);
	}

}

//Function to insert an elemnt at specified position
void insert(position p, int x) {
	position temp_cell = (position) malloc(sizeof(struct node));
	
	if(temp_cell == NULL) { printf("out of space\n"); exit(0); }
	
	temp_cell->data = x;
	temp_cell->next = p->next;
	
	p->next = temp_cell;
}

//Function to delete complete list
void delete_list(LIST L) {
	position p, tmp_cell;
	
	p = L->next;
	L->next = NULL;
	while(p!=NULL) {
		tmp_cell = p->next;
		free(p);
		p=tmp_cell;
	}
}

//Function to return length of the list
int length(LIST L) {
	position p = L->next;
	int count = 0;
	
	while(p!=NULL) {
		count++;
		p = p->next;
	}
	
	return count;
}

// Driver program to test the functions
int main() {
	//Declare start of LIST (head node)
	LIST L = (LIST) malloc(sizeof(struct node));
	L->next = NULL;
	
	if(is_empty(L)) printf("Empty List\n");
	
	L->next = (LIST) malloc(sizeof(struct node));
	L = L->next;
	
	L->data = 1;
	L->next = NULL;
	
	if(is_last(L)) printf("Last Element\n");
	
	return 0;
}
