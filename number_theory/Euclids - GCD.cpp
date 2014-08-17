#include<iostream>
using namespace std;

int gcd(int a, int b) {
	if(b==0) return a;
	else return gcd(b,a%b);
}

int main() {
	int a,b;
	cout<<"This program calculates GREATEST COMMON DIVISOR of 2 numbers using Euclids Algorithm\n";
	cout<<"\nEnter the numbers a annd b or 0 to exit: ";

	cin>>a;
	while(a!=0) {
		cin>>b;
		if(a>b) cout<<"The GCD of "<<a<<" and "<<b<<" is: "<<gcd(a,b)<<endl;
		else cout<<"The GCD of "<<a<<" and "<<b<<" is: "<<gcd(b,a)<<endl;
		cout<<"\nEnter the numbers a annd b or 0 to exit: ";
		cin>>a;
	}
		
	return 0;
}

