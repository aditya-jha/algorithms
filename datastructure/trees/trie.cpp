/*
    Standard Trie Implementation using array
    Aditya Jha
*/

#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

#define ALPHABET_SIZE 26
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')

typedef struct trie_node* trie_node_ptr;
typedef struct trie* trie_ptr;

struct trie_node {
    int value; //Used to mark leaf nodes
    trie_node_ptr children[ALPHABET_SIZE];
};    

struct trie {
    int count;
    trie_node_ptr root;
};

//Returns new trie node (initialized to NULLs) 
trie_node_ptr getNode(void) {
    trie_node_ptr pNode = NULL;
    
    pNode = (trie_node_ptr)malloc(sizeof(struct trie_node));
    
    if(pNode != NULL) {
        int i;
        pNode->value = 0;
        
        for(i=0;i<ALPHABET_SIZE;i++) pNode->children[i] = NULL;        
    }    
    
    return pNode;
}    

//Initializes trie (root is dummy node) 
void initialize(trie_ptr pTrie) {
    pTrie->root = getNode();
    pTrie->count = 0;
}    

//If not present, insert key into trie
//If the key is prefix of trie node, just mark leaf node
void insert(trie_ptr pTrie, char key[]) {
    int level;
    int length = strlen(key);
    int index;
    trie_node_ptr pCrawl;
    
    pTrie->count++;
    pCrawl = pTrie->root;
    
    for( level=0; level<length; level++ ) {
        index = CHAR_TO_INDEX(key[level]);
        if( !pCrawl->children[index] ) {
            pCrawl->children[index] = getNode();
        }    
        
        pCrawl = pCrawl->children[index];
    }    
    
    // mark last node as leaf
    pCrawl->value = pTrie->count;
}    

// Return non zero, if key is present in trie
int search(trie_ptr pTrie, char key[]) {
    int level;
    int length = strlen(key);
    int index;
    trie_node_ptr pCrawl;
    
    pCrawl = pTrie->root;
    
    for( level=0; level<length; level++ ) {
        index = CHAR_TO_INDEX(key[level]);
        
        if( !pCrawl->children[index] ) {
            return 0;
        }
        
        pCrawl = pCrawl->children[index];    
    }    
    
    return (0 != pCrawl && pCrawl->value);
}    

int main() {
    
    char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    struct trie Trie;
    
    char output[][32] = {"Not present in trie", "Present in trie"};
 
    initialize(&Trie);
 
    // Construct trie
    for(int i = 0; i < 8; i++)
    {
        insert(&Trie, keys[i]);
    }
 
    // Search for different keys
    printf("%s --- %s\n", "the", output[search(&Trie, "the")] );
    printf("%s --- %s\n", "these", output[search(&Trie, "these")] );
    printf("%s --- %s\n", "their", output[search(&Trie, "their")] );
    printf("%s --- %s\n", "thaw", output[search(&Trie, "thaw")] );
    
    system("pause");
    return 0;
}
     
