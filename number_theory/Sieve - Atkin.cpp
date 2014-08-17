/*
	Sieve of Atkin
	Aditya Jha
	28-dec-2013
*/

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

void sieve_of_atkin(int n) {
	bool *sieve = new bool[n+5]; //Array to hold prime numbers
	
	//Initailize the array to false;
	memset(sieve,false,sizeof(sieve));
	
	int lim = ceil(sqrt(n));
	
	//solve for x,y,k
	for(int x=1;x<=lim;x++) {
		for(int y=1;y<=lim;y++) {
			
			int temp = 4*x*x + y*y;
			if(temp<=n and (temp%12==1 or temp%12==5)) sieve[temp] ^= true;
			
			temp = 3*x*x + y*y;
			if(temp<=n and temp%12==7) sieve[temp] ^= true;
			
			temp = 3*x*x - y*y;
			if(x>y and temp<=n and x%12==11) sieve[temp] ^= true;
		}
	}
	
	//Mark all multiples of squares of primes found as non-primes
	for(int i=5;i<=lim;i++) {
		if(sieve[i]) {
			for(int j=i*i;j<n;j+=i*i) sieve[j] = false;
		}
	}
	sieve[0] = sieve[1] = sieve[4] = false;
	sieve[2] = sieve[3] = true;

	//Print the primes found
	for(int i=0;i<n;i++) {
		if(sieve[i]) cout<<i<<endl;
	}
}

int main() {
	int n;
	cin>>n;
	sieve_of_atkin(n+1);
	
	return 0;
}
