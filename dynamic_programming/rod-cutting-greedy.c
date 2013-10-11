#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int i,j;

int comp(const void *, const void *);

long int rod-cut-greedy(int p[], in n) {
	float den[n], max = 0;
	int max_index = 0;
	for(i=0; i<n; i++) den[i]= p[i];
	qsort(den,n,sizeof(float),comp);
	
}

int main() {
	int n;
	scanf("%d",&n);
	int p[n];
	for(i=0; i<n; i++) scanf("%d",&p[i]);

	printf("%li\n",rod_cut_greedy(p,n);

	return 0;
}
