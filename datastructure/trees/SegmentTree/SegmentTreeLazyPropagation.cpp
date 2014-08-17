#include<iostream>
#include<cstdio>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>

using namespace std;

#define min(a,b) (a<b?a:b)

int n=8;
const int maxn = 4*n+1;

int *arr;
int *tree;
int *lazy;

void build_tree(int index, int a, int b) {
    if(a>b) return; //out of range
    
    if(a==b) { // leaf node
        tree[index] = arr[a]; // leaf node contains the value in the array
        return;
    }    
    
    build_tree(2*index + 1, a, (a+b)/2);
    build_tree(2*index + 2, (a+b)/2 + 1, b);
    
    tree[index] = min(tree[2*index+1], tree[2*index+2]);
}    

// Update the arr in the range [i,j]
void update_tree(int index, int a, int b) {
    
}
    
int main() {
    arr = new int[n];
    tree = new int[maxn];
    lazy = new int[maxn];
    
//     = {5, 2, 4, 6, 11, 8, 3, 2};
    arr[0] = 5, arr[1] = 2, arr[2] = 4, arr[3] = 4, arr[4] = 6, arr[5] = 11, arr[6] = 8, arr[7] = 3, arr[8] = 2;
    
    // build the tree
    build_tree(0, 0, n-1);
    
    
    
    cout<<tree[4]<<endl;
    
    system("pause");
    return 0;
}    
