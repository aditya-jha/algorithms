#include<iostream>
#include<cstdio>

using namespace std;

void merge(int a[], int start, int mid, int end) {
    
    int i,j,k;
    int lenA = mid-start, lenB = end-mid+1;
    int *copyA = new int[lenA];
    int *copyB = new int[lenB];
    
    for(i=start,j=0;i<mid;i++) {
        copyA[j++] = a[i];
    }    
    
    for(int i=mid,j=0;i<=end;i++) {
        copyB[j++] = a[i];
    }    
    
    i=j=0;
    for(k=start;k<=end;k++) {
        if(i<lenA and j<lenB) {
            if(copyA[i] < copyB[j]) a[k] = copyA[i++];
            else a[k] = copyB[j++];
        }    
        else if(i<lenA) {
            a[k] = copyA[i++];
        }    
        else {
            a[k] = copyB[j++];
        }    
    }
    
    delete[] copyA;
    delete[] copyB;    
}    

int coun = 0;
void merge_sort(int a[], int start, int end) {
    if(start < end) {
        int mid = start + (end-start)/2;
        merge_sort(a,start,mid);
        merge_sort(a,mid+1,end);
        merge(a,start,mid+1,end);
    }    
}    

int main() {
    int a[] = {8,7,6,5,4,3,1};
    int n = 6;
    
    merge_sort(a,0,n);
    
    for(int i=0;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
    
    system("pause");
    return 0;
}    
