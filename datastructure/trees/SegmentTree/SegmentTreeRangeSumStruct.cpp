/*
    NOT working. Will have to debug
*/

#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>

using namespace std;

typedef struct node {
    int data;
    struct node* leftchild;
    struct node* rightchild;
};

void update(struct node* parent, int ss, int se, int i, int diff) {
    if(ss>i and se<i) {
        return;
    }    
    
    parent->data += diff;
    
    int mid = ss+(se-ss)/2;
    update(parent->leftchild,ss,mid,i,diff);
    update(parent->rightchild,mid+1,se,i,diff);
}    

int buildST(int *arr, int ss, int se, struct node** parent) {
    
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    
    if(ss == se) {
        newNode->data = arr[ss];
        newNode->leftchild = NULL;
        newNode->rightchild = NULL;
        
        (*parent) = newNode;
        
        return(*parent)->data;
    }    
        
    int mid = ss+(se-ss)/2;
    
    newNode->data = buildST(arr,ss,mid,&newNode->leftchild) + 
                    buildST(arr,mid+1,se,&newNode->rightchild);
    (*parent) = newNode;

    return (*parent)->data;
}    

int main() {
    int arr[5] = {0,1,2,3,4};
    
    struct node* root = NULL;
    
    buildST(arr,0,4,&root);
    
    cout<<root->data<<endl;
    
    arr[0] = 1;
    update(root,0,4,0,1);
    
    cout<<root->data<<endl;
    
    getchar();
    return 0;
}    
