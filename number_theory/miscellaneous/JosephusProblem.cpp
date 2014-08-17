/*
    Josephus Problem
    O(n) for small n
    for large n another solution O(klog n)
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

int josephus(int n, int k) {
    if(n == 1) return 1;
    
    else return (josephus(n-1,k)+k-1)%n +1;
}    

int main() {
    int n=14, k=2;
    cout<<josephus(n,k)<<endl;
    
    system("pause");
    return 0;
}    
