/*
	STATEMENT: Given a rod of length n, and a price table p containing revenue generated on selling rod of size i.
		   Find the maximum revenue possible?
	SOLUTION:  This is a top down dynamic algortihm to find just the optimal value, not the values that gave the optimal answer.

	This code is not giving correct answer and i am not able to find the bug :'(
*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define max(a,b) (a>b?a:b)

int i,j;

long int rod_cut_topdown(int p[], int n, int rev[]) {
	int q=-1;
	if(rev[n]>=0) return rev[n];
	if(n==0) q=0;
	else {
		for(i=1; i<=n; i++) q = max(q, p[i]+rod_cut_topdown(p,n-i,rev));
	}
	rev[n]=q;
	return q;
}

long int rod_cut(int p[], int n) {
	int rev[n+1];
	for(i=0; i<=n; i++) rev[i]=-1;
	long int x= rod_cut_topdown(p,n,rev);
	for(i=0; i<=n; i++) printf("%d ",rev[i]);
	return x;
}

int main() {
	int n;
//	printf("%d\n",max(2,3));
	scanf("%d",&n);
	int p[n+1]; p[0]=0;
	for(i=1; i<=n; i++) scanf("%d",&p[i]);
	
	printf("The optimal revenue is: %li\n", rod_cut(p,n));
	return 0;
}
