/*
    Loop detection
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

typedef struct node *node_ptr;

typedef struct node {
    int data;
    node_ptr next;
};

typedef node_ptr LIST;
typedef node_ptr position;

bool detectLoop(LIST list) {
    position pSlow,pFast;
    pSlow = list;
    pFast = list;
    
    while(pSlow != NULL or pFast != NULL) {
        pFast = pFast->next;
        
        if(pFast == pSlow) return true;
        
        if(pFast == NULL) return false;
        
        pFast = pFast->next;
        
        if(pFast == pSlow) return true;
    }    
    
    return false;
}        

int main() {
    LIST head = (LIST)malloc(sizeof(struct node));
    position p = head;
    
    p->data = 1;
    p->next = NULL;
    
    position q = (LIST)malloc(sizeof(struct node));
    p->next = q;
    
    q->data = 2;
    q->next = (LIST)malloc(sizeof(struct node));
    
    q = q->next;
    q->data = 3;
    q->next = p;
    
    if(detectLoop(head)) cout<<"yes\n";
    
    system("pause");
    return 0;
}    
