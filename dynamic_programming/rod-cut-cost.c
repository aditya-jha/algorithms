#include<stdio.h>

int i,j;

long int cut_rod_cost(int p[], int n, int c) {
	long int r[n+1];
	int s[n+1];
	r[0]=0;
	for(i=1; i<=n; i++) {
		int q = -1;
		for(j=1; j<=i; j++) {
			if(q<p[j]+r[i-j]-c) {
				q = p[j]+r[i-j]-c;
				s[i]=j;
			} 
		}
		r[i]=q;
		//printf("%li ",r[i]);
	}
	int x=n;
	while(n>0) { printf(" %d ",s[n]); n=n-s[n]; }
	return r[x];
}

int main() {
	int n,c;
	scanf("%d",&n);
	scanf("%d",&c);
	int p[n+1];
	p[0]=0;
	for(i=1; i<=n; i++) scanf("%d",&p[i]);

	printf("\nOptimal solution is: %li\n",cut_rod_cost(p,n,c));
	return 0;
}

