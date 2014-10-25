#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int myPowIterative(int a, int n) {
    int ret = 1;
    
    while(n != 0) {
        if(n%2 != 0) {
            ret = ret*a;
        }    
        a = a*a;
        n >>= 1;
    }    
    
    return ret;
}    

int myPowRecursive(int a, int n) {
    if(n == 0) return 1;
    else if(n%2 == 0) {
        return myPowRecursive(a, n/2)*myPowRecursive(a,n/2);
    }    
    else return a*myPowRecursive(a, n/2)*myPowRecursive(a,n/2);
}    
int main() {
    int n,a;
    a = 7, n = 2;
    
    cout<<myPowIterative(a,n)<<endl;
    cout<<myPowRecursive(n,a)<<endl;
    
    cin>>a;
    return 0;
}    
