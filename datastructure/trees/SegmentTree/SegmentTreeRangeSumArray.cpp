/*
Aditya Jha
Segment Tree implementation for range sum using array
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<climits>
#include<string>
#include<cstring>

using namespace std;

void updateValue(int *st, int ss, int se, int at, int diff, int index) {
    if(at<ss || at>se) return;
    
    //add the diff to the segment tree node
    st[index] += diff;
    
    //if we reached the leaf node
    if(ss==se) return;
    
    //recursively compute 
    int mid = ss+(se-ss)/2;
    updateValue(st,ss,mid,at,diff,2*index+1);
    updateValue(st,mid+1,se,at,diff,2*index+2); 
}    

void update(int *a, int *st, int n, int at, int val) {
    int diff = val - a[at];
    a[at] = val;
    
    updateValue(st,0,n-1,at,diff,0);
}    

int getSumFunc(int *st, int ss, int se, int qs, int qe, int index) {
    //if segment is completly contained
    if(qs<=ss and qe>=se) return st[index];
    
    //segment is completly out
    if(qs>se or qe<ss) return 0;
    
    int mid = ss + (se-ss)/2;
    return getSumFunc(st,ss,mid,qs,qe,2*index+1) + 
            getSumFunc(st,mid+1,se,qs,qe,2*index+2);
}    

int getSum(int *st, int n, int qs, int qe) {
    return getSumFunc(st,0,n-1,qs,qe,0);
}    

int constructSegmentTree(int *a, int si, int ei, int *st, int index) {
    //if we reached leaf node
    if(si == ei) {
        st[index] = a[si];
        return a[si];
    }    
    
    //recursively build the left child at 2*index+1 and right at 2*index + 2
    int mid = si + (ei-si)/2;
    st[index] = constructSegmentTree(a,si,mid,st,2*index+1) + 
                constructSegmentTree(a,mid+1,ei,st,2*index+2);
    return st[index];
}    

int *segmentTree(int *a, int n) {
    //allocate memory to hold segment tree
    int *st = new int[2*n+1];
    
    //contruct the tree
    constructSegmentTree(a,0,n-1,st,0);
    
    //return the contructed tree
    return st;
}    

int main() {
    ios_base::sync_with_stdio(0);
    
    int a[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(a)/sizeof(a[0]);
    
    int *st = segmentTree(a,n);
    
    int t;
    cin>>t;
    while(t--) {
        int x,y;
        cin>>x>>y;

        cout<<getSum(st,n,x,y)<<endl;
        
        int val, index;
        cin>>index>>val;
        
        update(a,st,n,index,val);
    }    
    
    return 0;
}    
