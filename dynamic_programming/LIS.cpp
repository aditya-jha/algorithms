#include<iostream>
#include<climits>
#include<cstring>

using namespace std;

#define min(a,b) (a<b?a:b)

int LIS(int *a, int n) {
    int lis[n];
    for(int i=0;i<n;i++) lis[i] = INT_MIN;
    
    lis[0] = 0;
    lis[1] = 1;
    
    for(int i=2;i<n;i++) {
        for(int j=i-1;j>0;j--) {
            if(a[j]<=a[i]) {
                lis[i] = max(lis[i], 1+lis[j]);
            }    
        }    
//        cout<<i<<" "<<lis[i]<<endl;
    }  
    
    return lis[n-1]; 
}    


int main() {
    int a[] = {0, 10, 22, 9, 33, 21, 50, 41, 60, 80};
    int n=10;
    
    cout<<LIS(a,n)<<endl;
    
    system("pause");
    return 0;
}    

