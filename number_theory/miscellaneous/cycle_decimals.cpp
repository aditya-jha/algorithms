/*
	Program to find the cycle lenght of when some integer a is divided by n and has non-terminating decimal representation.
*/

#include<iostream>
#include<vector>
using namespace std;

vector<int> r;

int get_digits(int n) {
	int d = 0;
	while(n != 0) {
		n = n/10;
		d++;
	}
	return d;
}

bool find(int r[],int rem,int index) {	
	for(int i=0; i<index; i++)
		if(r[i] == rem) {return true;}

	return false;
}

int main() {

	int n,max=0,max_n=1;
	cout<<"enter n(0 to exit): ";
	cin>>n;

	while(n != 1) {
		int length = 1, digits = get_digits(n), index = 0;
		vector<int> q;
		int r[10000] = {0};
		//cout<<"digits: "<<digits<<endl;
		int quo = 0,rem = 0;
		int number = 1;
		for(int i=0; i<digits; i++) number *=10;
		//cout<<"number: "<<number<<endl;
		while(digits-1>0) {
			q.push_back(0);
			digits--;
		}
		rem = number%n;
		quo = number/n;
		
		q.push_back(quo);
		r[index] = rem;
		index++;

		while(true) {
			number = rem*10;
			//cout<<"number: "<<number<<endl;
			rem = number%n;
			quo = number/n;
			//cout<<"rem: "<<rem<<endl;
			if(rem == 0) {
				length = 0;
				break;
			} else {
				if(find(r,rem,index)) break;
				else {
					r[index] = rem;
					index++;
					q.push_back(quo);
					length++;
				}
			}
		}
					
		//cout<<endl;
		//for(int i=0; i<q.size(); i++) cout<<q[i];

		if(length>max) {
			max = length;
			max_n = n;
		}
		cout<<"n: "<<n<<" length: "<<length<<endl;		

		//cout<<"enter n(0 to exit): ";
		//cin>>n;
		n--;
	}
	cout<<"max: "<<max<<" max_n: "<<max_n<<endl;

	return 0;
}
