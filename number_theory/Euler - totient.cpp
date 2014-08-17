#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

int euler_totient(int n) {
    int ret = n;
    
    for(int i=2;i*i<=n;i++) {
        if(n%i==0) ret -= ret/i;
        
        while(n%i == 0) n = n/i;
    }
    
    if(n>1) ret -= ret/n; 
    
    return ret;
}    

int main() {
    ios_base::sync_with_stdio(0);
    
    int n=10;
    
    cout<<n<<" : "<<euler_totient(n)<<endl;
    
    system("pause");
    return 0;
}    
