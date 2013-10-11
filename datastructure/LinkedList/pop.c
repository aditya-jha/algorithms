/*****************************************************************************************

	Write a Pop() function that is the inverse of Push(). Pop() takes a non-empty
	list, deletes the head node, and returns the head node's data.
	
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

LIST BuildOneTwoThree(LIST L);
int pop(struct node** headRef);
int length(LIST L);

int main() {
	LIST head = (LIST)malloc(sizeof(struct node));
	
	head = BuildOneTwoThree(head);
	
	printf("%d\n",pop(&head));	
	printf("%d\n",pop(&head));	
	printf("%d\n",pop(&head));	
	
	printf("%d\n",length(head));	
	
	return 0;
}

int length(LIST L) {
	position p = L->next;
	int count = 0;
	
	while(p!=NULL) {
		count++;
		p = p->next;
	}
}

int pop(struct node** headRef) {
	if(*headRef==NULL) {
		printf("List Empty\n");
		return -1;
	}
	position p = *headRef;
	p=p->next;
	int val = p->data;
	*headRef=p;
	free(p);
	return val;	
}


LIST BuildOneTwoThree(LIST L) {
	position one=NULL, two=NULL, three=NULL;
	
	one = (position) malloc(sizeof(struct node));
	two = (position) malloc(sizeof(struct node));
	three = (position) malloc(sizeof(struct node));
	
	L->next = one;
	one->data = 1;
	
	one->next = two;
	two->data = 2;
	
	two->next = three;
	three->data = 3;
	
	three->next = NULL;
	
	return L;
}
