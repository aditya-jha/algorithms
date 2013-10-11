#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define max(a,b) (a>b?a:b)

int i,j;

void print_solution(int s[], int n) {
	while(n>0) {
		printf("%d ",s[n]);
		n = n - s[n];
	}
	printf('\n')
}

long int rod_cut_bottomup(int p[], int n) {
	long int r[n+1];
	int s[n+1];
	r[0]=0;
	for(j=1; j<=n; j++) {
		int q = -1;
		for(i=1; i<=j; i++) if(q < p[i]+r[j-i]) { q = p[i]+r[j-i]; s[j]=i; }
		r[j]=q;
	}
	print_solution(s,n);
	return r[n];
} 

int  main() {
	int n;
	scanf("%d", &n);
	int p[n+1]; p[0]=0;
	for(i=1; i<=n; i++) scanf("%d",&p[i]);
	printf("%li\n",rod_cut_bottomup(p,n));
	return 0;
}
