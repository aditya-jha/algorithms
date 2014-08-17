/*
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define llu long long unsigned 

vector<llu> v;

llu multiply(llu a,llu b, llu c) {
	llu total=0;
	if(b<a) swap(a,b);
	
	if((a%2) != 0)  total = (total+b)%c;
	
	while(a!=1) {
		a = a>>1;
		b = b<<1;
		
		if((a%2) != 0)  total = (total+b)%c;
	}
	
	return total;
}

int main() {
	int a,b,c;
	
	cin>>a>>b>>c;
	while(a!=0) {
		cout<<multiply(a,b,c)<<endl;
	
		cin>>a>>b>>c;
	}
	return 0;
}
