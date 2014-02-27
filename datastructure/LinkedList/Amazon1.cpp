#include<stdio.h>
#include<stdlib.h>

using namespace std;

typedef struct node* node_ptr;

typedef struct node {
    void *data;   
    node_ptr next;
};    

typedef node_ptr LIST;
typedef node_ptr pointer;

void pushd(LIST *head, int val) {
    pointer p = (LIST)malloc(sizeof(struct node));
    
    (int *)p->data = val;
    p->next = *head;
    
    *head = p;
}

void push(LIST *head, char c) {
    pointer p = (LIST)malloc(sizeof(struct node));
    
    (char *)p->data = c;
    p->next = *head;
    
    *head = p;
}        

void print(LIST list) {
    pointer p = list;
    
    while(p != NULL) {
        if(sizeof(p->data) == sizeof(char)) printf("%c ",p->data);
        else printf("%d ",p->data);
        p = p->next;
    }    
}    

int main() {
    LIST head = NULL;
    
    pushd(&head, 1);
    pushd(&head, 2);
    pushd(&head, 3);
    push(&head, 'a');
    pushd(&head, 4);
    push(&head, 'b');
    pushd(&head, 5);
    push(&head, 'c');
    push(&head, 'd');
    print(head);
    
    system("pause");
    return 0;
}    
