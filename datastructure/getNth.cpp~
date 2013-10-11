/*************************************************************************************

	Given a list and an index, return the data in the nth node of the list.
	The nodes are numbered from 0. Assert fails if the index is invalid
	
	Aditya Jha
	29-sep-2013
	
**************************************************************************************/

#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cassert>

typedef struct node* node_ptr;

struct node {
	int data;
	node_ptr next;
};

typedef node_ptr position;
typedef node_ptr LIST;

LIST BuildOneTwoThree(LIST L);
int getNth( LIST L, int n );

int main() {
	LIST head = (LIST)malloc(sizeof(struct node));
	head = BuildOneTwoThree(head);
	
	int value = getNth(head,2);
	printf("%d\n",value);
	
	return 0;
}

int getNth(LIST L, int n) {
	int val = 0, pos=0;
	assert(n>-1 && n<3);
	position p = L->next;
	
	while(pos++ != n) p=p->next;
	
	return p->data;
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
