#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int con=0;

void permute(int *a, int i) {
    if(i==9) {
        con++;
        for(int j=0;j<10;j++) cout<<a[j];
        cout<<endl;
    }
    else {    
        for(int j=i;j<10;j++) {
            swap(a[i],a[j]);
            permute(a,i+1);
            swap(a[i],a[j]);
        }    
    }    
}    

int main() {
    int a[] = {0,1,2,3,4,5,6,7,8,9};
    permute(a,0);
    
    cout<<con<<endl;
    
    int f=1;
    for(int i=1;i<11;i++) f*=i;
    cout<<f<<endl;
    
    system("pause");
    return 0;
}    
