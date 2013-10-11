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
