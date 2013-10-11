/*
	Finding s%n where s=string containing digits from 0 to 9 and n=natural number
*/


#include<iostream>
#include<string>
#include <sstream> 
using namespace std;

long long unsigned int getvalue(string s) {
	unsigned long long int ret=0;
	
	for(int i=0; i <s.length(); i++)
		ret=ret*10+int(s[i])-'0';
	
	return ret;
}

unsigned long long modulo(string s, int m) {
	int d = 16;
	
	if(s.length() > d) {	
		string temp = s.substr(0,d);;
		cout<<"temp: "<<temp<<endl;
		s = s.substr(d);
		//cout<<"nbig: "<<s<<endl;
		
		unsigned long long int tempnum = getvalue(temp);
		//cout<<tempnum-1<<endl;
		tempnum = tempnum % m;
		//cout<<"tempnum: "<<tempnum<<endl;
		
		temp = static_cast<ostringstream*>( &(ostringstream() << tempnum) )->str();
		
		temp += s;
		//cout<<"nbig: "<<s<<endl;
	
		return modulo(temp,m);
	} else {
		unsigned long long int tempnum = getvalue(s);
		tempnum = tempnum % m;
		
		return tempnum;
	}
}

int main() {
	string s = "123456789033333333335555555555";
	int length = s.length();
	
	cout<<modulo(s,320)<<endl;	
	cout<<getvalue("11111111111111111") - 1<<endl;
	
	char c[10];
	c[0] = '1';
	c[1] = '2';

	cout<<sizeof(c)<<endl;
	return 0;
}
