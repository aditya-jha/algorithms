#include<stdio.h>
#include<stdlib.h>

#define SIZE 5

int *tos, *p1, stack[SIZE];

void push(int i);
int pop(void);

int main(void) {
	int value;
	
	tos = stack;
	p1 = stack;	

	do {
		printf("Enter value to be stored or 0 to pop -1 to terminate: ");
		scanf("%d",&value);
		if(value != 0)	 push(value);
		else printf("%d",pop());
	} while(value != -1);

	return 0;
}

void push(int i) {
	if(tos >= p1+SIZE) {
		printf("Stack Overflow\n");
		exit(1);
	} else {
		*tos = i;
		tos++;
	}
}

int pop(void) {
	tos--;
	if(tos < p1) {
		printf("Stack Underflow\n");
		exit(1);
	} else return *tos;
}
