#include<stdio.h>

int main() {
	int n,i;
	printf("Enter n(-1 to exit): ");
	scanf("%d",&n);

	while(n!=-1) {
		int f[n+1];
		f[0]=0; f[1]=1;
		for(i=2; i<=n; i++) f[i] = f[i-1]+f[i-2];
		printf("%d\n",f[n]);
		scanf("%d",&n);
	}
	return 0;
}
