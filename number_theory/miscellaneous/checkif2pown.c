#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main() {
	int n=1;
	scanf("%d",&n);
	while(n!=0) {
		
		if(log2(n)==floor(log2(n))) printf("yes %d\n",log2(n));
		else printf("NO\n");
		scanf("%d",&n);
	}
	return 0;
}

