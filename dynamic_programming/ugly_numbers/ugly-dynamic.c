#include<stdio.h>
#include<stdlib.h>

#define min(a,b,c) (a>b?(b<c?b:(c<a?c:a)):(a<c?a:(c<b?c:b)))

unsigned getUgly(int n) {
	int *ugly = (int *) (malloc(sizeof(int)*n));
	unsigned i2=0, i3=0, i5=0;
	unsigned next_2=2, next_3=3, next_5=5,i;
	unsigned next_ugly = 0;
	*(ugly+0) = 1;
	
	for(i=1; i<n; i++) {
		next_ugly = min(next_2,next_3,next_5);
		*(ugly+i) = next_ugly;
		if(next_ugly == next_2) { i2++; next_2 = *(ugly+i2)*2; }
		if(next_ugly == next_3) { i3++; next_3 = *(ugly+i3)*3; }
		if(next_ugly == next_5) { i5++; next_5 = *(ugly+i5)*5; }
	}
	return next_ugly;
}

int main() {
	printf("%d\n",getUgly(11));
	return 0;
}	
