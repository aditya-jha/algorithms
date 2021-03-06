/*************************************************************************************

	Write a function DeleteList() that takes a list, deallocates all of its
	memory and sets its head pointer to NULL
	
	Aditya Jha
	29-sep-2013
	
**************************************************************************************/

#include<stdio.h>
#include<stdlib.h>

typedef struct node* node_ptr;

struct node {
	int data;
	node_ptr next;
};

typedef node_ptr position;
typedef node_ptr LIST;

LIST BuildOneTwoThree(LIST L);
void deleteList(struct node** L);
int length(LIST L);

int main() {
	LIST myList = (LIST)malloc(sizeof(struct node));
	myList = BuildOneTwoThree(myList);
	
	deleteList(&myList);
	
	
	myList = (LIST)malloc(sizeof(struct node));
	
	printf("Length of the List: %d\n",length(myList));
	
	myList = BuildOneTwoThree(myList);
	
	printf("data: %d\n",myList->next->data);
	
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

void deleteList(struct node** L) {
	if(*L == NULL) {
		printf("List Already Empty");
	}
	position p = *L, temp = *L;
//	printf("%d\n",p->data);
	p = p->next;
	*L = NULL;
	while(p!=NULL) {
		temp = p;
		p=p->next;
		free(temp);
	}	
		
	free(p);
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
