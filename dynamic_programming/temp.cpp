#include<iostream>
#include<cstdio>
using namespace std;

//enum fing = {thumb, first, middle, ring,  little};

void value(int n) {
	if(n==1) printf("thumb\n");
	else if(n==2) printf("first\n");
	else if(n==3) printf("middle\n");
	else if(n==4) printf("ring\n");
	else printf("little\n");

}

int main() {
	int n,t;
	cin>>n;
	t=n;
//	finger fing;
	if(t<=5) { value(t); }
	else {
		//while(true) {
			n=n-5;
			int q = n/4;
			if(q%2==0) { value(5-(n%4)); }
			else { value((n%4)+1);}
		//}
	}
	return 0;
}
