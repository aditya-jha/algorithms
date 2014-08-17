#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;

bool primes[100001];
vector<int> pp;
void sieve(int n) {
	memset(primes,true,sizeof(primes));
	primes[0]=primes[1]=false;
	
	int lim = ceil(sqrt(n));
	for(int i=2;i<=lim;i++) {
		if(primes[i]) {
			pp.push_back(i);
			for(int j=i*i;j<=n;j+=i) { //i*i may not be able to hold int, check will solving questions
				primes[j]=false;
				
			}
		}
	}
	pp.push_back(100000000);
}

void segmented_sieve(int a,int b) {
	int index = b-a+1;
	
	bool *arr = new bool[index+1];
	for(int i=0;i<index;i++) arr[i]=true;

	int lim = sqrt(b);
	for(int i=0;pp[i]<lim;i++) {
		int j=a/pp[i];
		if(j*pp[i]<a) j++;
		
		for(j=j*pp[i];j<=b;j+=pp[i]) arr[j-a]=false;
	}
	
	for(int i=0;i<index;i++) {
		if(arr[i]==true) print_d(i+a);
	}

	delete[] arr;
}

int main() {
	int a = 100000;
	sieve(a);
	cout<<sqrt(1000000000)<<endl;
	return 0;
}
