/*
	Program to solve TOWER OF HANOI problem
	Aditya Jha
	00.01 am 30 august 2013

*/

#include<stdio.h>

int count=0;

void towers(int m, char from, char to, char via);

int main() {
	int n;
	scanf("%d", &n);
	towers(n,'A','B','C');
	printf("Total moves: %d\n",count);
}

void towers(int m, char from, char to, char via) {
	count++;
	if(m==1) {
		printf("move from %c to %c\n", from, to);
		//return;
	} else {
		towers(m-1,'A','C','V');
		printf("move from %c to %c\n", from, to);
		towers(m-1,'C','B','A');
	}
	
}
