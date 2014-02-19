/*
	If n&(n-1) is zero then n is a power of 2.
	The main reason behind this is in the binary representation of n
	If n is a power of 2 then it will be of the form 1000... and 
	n-1 will be of the form 1111.... 
	Taking & of these two numbers results into 0.
*/

#include<iostream>
#include<cstdio>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	while(n!=0) {
		if((n&(n-1)) == 0 ) cout<<n<<" yes\n";
		else cout<<n<<" no\n";
		cin>>n;
	}
	
	return 0;
}
