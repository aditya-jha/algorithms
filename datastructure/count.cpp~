/**********************************************************************************

	Given a list and an int, return the number of times that int occurs
	in the list.
	
	Aditya Jha
	29-sep-2013
	
***********************************************************************************/



#include<cstdio>
#include<iostream>
#include<cstdlib>

using namespace std;

typedef struct node* node_ptr;

struct node {
	int data;
	struct node* next;
};

typedef node_ptr LIST;
typedef node_ptr position;


LIST BuildOneTwoThree(LIST L);
int count( LIST L, int n );

int main() {
	LIST head = (LIST) malloc(sizeof(struct node));
	head = BuildOneTwoThree(head);
	
	int counter = count(head,2);
	
	printf("%d\n",counter);
	
	return 0;
}

int count( LIST L, int n ) {
	int counter = 0;
	
	position p = L->next;
	
	while(p!=NULL) {
		if(p->data==n) counter++;
		p = p->next;
	}
	
	return counter;
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



