// QUICK-SORT alogrithm

#include<iostream>
#include<algorithm>
using namespace std;

int partition(int a[], int p, int r) {
	int x = a[r], i = p-1;
	for(int j=p; j<r; j++) {
		if(a[j] <= x) {
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[r]);
	return i+1;
}

void quicksort(int a[], int p, int r) {
	if(p<r) {
		int q = partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}

int main() {
	int a[] = {2,4,3,8,6,10,9,7,1,5};
	int r = 9;
	
	for(int i=0; i<=r; i++) cout<<a[i]<<" ";
	cout<<endl;
	
	quicksort(a,0,r);

	for(int i=0; i<=r; i++) cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
