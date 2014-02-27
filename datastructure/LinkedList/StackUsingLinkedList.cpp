#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

typedef struct node *node_ptr;

typedef struct node {
    int data;
    node_ptr next;
};

typedef node_ptr LIST;
typedef node_ptr position;

class Stack {
    private:
        LIST head;
        int count;
    public:
        Stack() {
            count = 0;
            head = NULL;
        }    
        
        int top() {
            if(count != 0) {
                return head->data;
            }    
            else {
                cout<<"Stack Empty\n";
                return -1;
            }    
        }    
        
        void push(int val) {
            position p = (LIST)malloc(sizeof(struct node));
            
            if(p == NULL) {
                cout<<"unable\n";
                return;
            }    
            p->data = val;
            p->next = head;
            
            head = p;
            
            count++;
        }    
        
        void pop() {
            if(count != 0) {
                position p = head;
                head = head->next;
                free(p);
                count--;
            }    
            else {
                cout<<"Stack Empty\n";                
            }    
        }  
        
        int length() {
            return count;
        }    
        
        void print() {
            position p = head;
            while(p != NULL) {
                cout<<p->data<<" ";
                p = p->next;
            }    
            cout<<endl;
        }      
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    
    s.print();
    
    int top = s.top();
    cout<<top<<endl;
    s.print();
    s.pop();
    s.print();
    top = s.top();
    s.pop();
    cout<<top<<endl;
    top = s.top();
    
    system("pause");
    return 0;
}    
