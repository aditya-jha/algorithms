#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

int rodCutting(int p[], int n) {
	int *revenue = 	new int[n+1];
	revenue[0] = 0;
	
	for(int i=1;i<=n;i++) {
		int q = -1;
		for(int j=1;j<=i;j++) {
			q = max(q,p[j]+revenue[i-j]);
		}
		revenue[i] = q;
	}
	
	for(int i=0;i<=n;i++) cout<<revenue[i]<<" ";
	cout<<endl;
	
	return revenue[n];
}

int main() {
	int n=10;
	int p[] = {0,1,5,8,9,10,17,17,20,24,30};
	
	cout<<rodCutting(p,n)<<endl;
	
	return 0;
}
