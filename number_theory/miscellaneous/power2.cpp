#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int n=1;
	cin>>n;
	while(n!=0) {
		if(log2(n)==int(log2(n))) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
		cin>>n;
	}
	return 0;	
}
