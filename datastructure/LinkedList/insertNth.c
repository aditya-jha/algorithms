/*****************************************************************************************

	write a function InsertNth() which can insert a new node at any index
	within a list
	
	Aditya Jha
	29-sep-2013
	
******************************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct node* node_ptr;

struct node {
	int data;
	node_ptr next;
};

typedef node_ptr position;
typedef node_ptr LIST;

void insertNth( struct node** ref, int pos, int val );
void Push(struct node** headRef, int newData);

int main() {
	struct node* head = NULL;
	
	insertNth(&head,0,13);
	insertNth(&head,1,12309);
	printf("%d\n",head->next->data);
	
	return 0;
}

void Push(struct node** headRef, int newData) {
	struct node* newNode = (struct node*) malloc(sizeof(struct node));

	newNode->data = newData;

	newNode->next = (*headRef);

	(*headRef) = newNode;
}

void insertNth( struct node** ref, int pos, int val ) {
	
	if(pos==0) Push(ref,val);
	else {
		struct node* current = *ref;
		int i;
		for (i=0; i<pos-1; i++) {
			assert(current != NULL);
			current = current->next;
		}
		
		assert(current != NULL);
		
		Push(&(current->next), val);
	}
}
