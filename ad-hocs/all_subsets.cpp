#include<iostream>
#include<cmath>

using namespace std;

void generate_subsets(int *a, int n) {
    int max_size = (int)pow(2.0,(double)n);
    
    for(int i=0;i<max_size;i++) {
        for(int j=0;j<n;j++) {
            if(i & (1<<j)) cout<<a[j];
        }    
        cout<<endl;
    }    
}    

int main() {
    int a[] = {1,2,3};
    int n=3;
    
    generate_subsets(a,n);
    
    system("pause");    
    return 0;
}    
