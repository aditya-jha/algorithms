#include<iostream>
#include<algorithm>
using namespace std;

int partition(int a[], int p, int r) {
	int x = a[r], i = p-1;
	
	for(int j = p; j<r; j++) {
		if(a[j] <= x) {
			i++;
			swap(a[i],a[j]);
		}
	}
	swap(a[i+1],a[r]);
	
	return i+1;
}

int randomized(int a[], int p, int r, int i) {
	if(p == r) return a[p];
	
	int q = partition(a,p,r);
	int k = q-p+1;

	if(i == k) 
		return a[q];
	else if(i<k) 
		return randomized(a,p,q-1,i);
	else
		return randomized(a,q+1,r,i-k);
}

int main() {
	int n,j;
	cout<<"This program calculates ith term in a array in linear time (O(n)) using RANDOMIZED algorithm\n";
	
	cout<<"Enter # of terms in array: ";
	cin>>n;

	int a[n];

	for(int i=0; i<n; i++) cin>>a[i];
	
	cout<<"Enter the order statistic to be found: ";
	cin>>j;

	cout<<randomized(a,0,n-1,j)<<endl;

//	for(int i=0; i<n; i++) cout<<a[i]<<" ";

	return 0;
}
