#include<iostream>
#include<cstdio>
//#include<algorithm>

using namespace std;

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *a = temp;
}    

void min_heapify(int a[], int index, int n) {
    int left = 2*index+1, right = 2*index+2;
    if(left<n and right<n) {
        if(a[left]<a[index]) {
            //left child is less than parent
            if(a[right]<a[index]) {
                //both left and right child are less than parent
                if(a[left] < a[right]) {
                    //left child is less than right child and parent
                    //swap left child with parent
                    swap(a[left], a[index]);
                    min_heapify(a,left,n);
                    return;
                }    
                else {
                    //right child is less than left child and parent
                    //swap right child with parent
                    swap(a[right], a[index]);
                    min_heapify(a,right,n);
                    return;
                }    
            }
            else {
                //swap left child with parent
                swap(a[left], a[index]);
                min_heapify(a,left,n);
                return;
            }    
        } 
        else if(a[right] < a[index]) {
            //swap right child with parent
            swap(a[right], a[index]);
            min_heapify(a,right,n);
            return;
        }    
    }    
    else if(left < n and a[left] < a[index]) {
        //swap left child with parent
        swap(a[left], a[index]);
        min_heapify(a,left,n);
        return;
    }    
}    

void build_heap(int a[], int n) {
    for(int i=(n-1)/2; i>=0; i--) {
        min_heapify(a, i, n);
    }    
}    

void delete_min(int a[], int n) {
    swap(a[0], a[n-1]);
    n--;
    min_heapify(a, 0, n);
}    

void heap_sort(int a[], int n) {
    for(int i=0;i<n;i++) delete_min(a, n-i);
}    

int main() {
    
    int a[] = {17,10,9,2,5,8};
    int n = 6;
    
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    
    min_heapify(a,0,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    
    build_heap(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    
    heap_sort(a,n);
    cout<<"After sorting: ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<endl;
    
    system("pause");
    return 0;
}    
