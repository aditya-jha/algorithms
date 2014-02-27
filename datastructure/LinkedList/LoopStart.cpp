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

int detectLoop(LIST list) {
    position pSlow,pFast;
    pSlow = list;
    pFast = list;
    bool loopExist = false;
    
    while(pSlow != NULL or pFast != NULL) {
        pFast = pFast->next;
        
        if(pFast == pSlow) {
            loopExist = true;
            break;
        }    
        
        if(pFast == NULL) return false;
        
        pFast = pFast->next;
        
        if(pFast == pSlow) {
            loopExist = true;
            break;
        }
    }    
    if(loopExist) {
        pSlow = list;
        while(pSlow != pFast) {
            pFast = pFast->next;
            pSlow = pSlow->next;
        }    
        return pSlow->data;
    }    
    return -1;
    
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
    
    if(detectLoop(head) != -1) cout<<"yes\n";
    
    system("pause");
    return 0;
}    
