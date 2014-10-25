/*
    Generating all subusets
    Method from programming challenges book
*/

#include<iostream>
#include<cstdio>

using namespace std;

bool finished = false;
int maxn;

bool is_a_solution(int *a, int k, int n) {
    return (n==k);
}    

void construct_solution(int *a, int k, int n, int *c, int *ncandidates) {
    c[0] = true;
    c[1] = false;
    *ncandidates = 2;
}    

void process_solution(int *a, int k) {
    printf("{");
    
    for(int i=1;i<=k;i++) {
        if(a[i]) printf(" %d",i);
    }
    
    printf(" }\n");    
}

void backtrack(int *a, int k, int n) {
    int c[2];
    int ncandidates;
    
    if(is_a_solution(a,k,n)) {
        process_solution(a,k);
    }    
    else {
        k++;
        construct_solution(a,k,n,c,&ncandidates);
        
        for(int i=0;i<ncandidates;i++) {
            a[k] = c[i];
            backtrack(a,k,n);
            if(finished) return;
        }    
    }    
}        

int main() {
    int a[4];
    backtrack(a,0,3);
    
    cin>>finished;
    return 0;
}    
