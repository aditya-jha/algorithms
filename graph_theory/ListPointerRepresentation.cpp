#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>

using namespace std;

struct ListNode {
    int dest;
    int weight; // comment out for unweighted graph
    
    struct ListNode* next;
};    

struct AdjList {
    struct ListNode* head;
};

// Struct to hold graph
struct Graph {
    int vertices; // # of vertices in graph
    struct AdjList* array; // array to hold edge information    
};   

struct Graph* createGraph(int n) {
    struct Graph* g = (struct Graph*) malloc(sizeof(struct Graph));
    g->vertices = n;
    
    g->array = (struct AdjList*)malloc(n*sizeof(struct AdjList));
    
    for(int i=0;i<n;i++) {
        g->array[i].head = NULL;        
    }    
    
    return g;
}      

void addEdge(struct Graph* g, int src, int dest) {
    struct ListNode* newNode = new ListNode[1];
    newNode->dest = dest;
    newNode->next = g->array[src].head;
    g->array[src].head = newNode;
}    

int main() {
    return 0;
}    
