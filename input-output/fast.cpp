#include<iostream>
#include<cstdio>

template<typename type> inline type scan(type i) {
	type ip = getchar_unlocked(), ret=0;
	for(;ip<'0'||ip>'9';ip=getchar_unlocked());
	for(;ip>='0' && ip<='9'; ip=getchar_unlocked()) ret = ret*10+ip-'0';
	return ret;
}

template<typename type> inline void print(type n) {
	int i=21;
	char output_buffer[22];
	output_buffer[21]='\n';
	do { output_buffer[--i]=(n%10)+'0'; n/=10; } while(n);
	do { putchar_unlocked(output_buffer[i]); } while(++i<22);
}

int main() {
	unsigned long long int i=scan(i);
	print(i);
	return 0;
}


/*
	fast i/o with sign
	
	#include<iostream>
#include<stdio.h>
#include<cmath>
#include<cstring>
#include<stdlib.h>
#include<algorithm>
#define getcx getchar_unlocked
#ifndef ONLINE_JUDGE
#define getcx getchar
#endif
using namespace std;
inline int in( )//fst input function
{
int n=0;
int ch=getcx();int sign=1;
while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getcx();}
 
while( ch >= '0' && ch <= '9' )
n = (n<<3)+(n<<1) + ch-'0', ch=getcx();
return n*sign;
}
*/
