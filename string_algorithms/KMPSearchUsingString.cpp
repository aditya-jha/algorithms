/*
    KMP Algorithm C++ implementation using string class
*/

#include<iostream>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

void computeLPS(string pat, int *lps) {
    int i=1, m=pat.length(), len = 0; //len = length of the previous longest prefix suffix
    lps[0] = 0;
    
    while(i<m) {
        if(pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }    
        else {
            if(len != 0) {
                len = lps[len-1]; //we do not increment i here
            }    
            else {
                lps[i] = 0;
                i++;
            }    
        }    
    }    
}    

void KMPSearch(string pat, string text) {
    int n = text.length();
    int m = pat.length();
    
    int *lps = new int[m];
    
    computeLPS(pat, lps);
    
    int i=0, j=0;
    while(i<n) {
        if(pat[j] == text[i]) {
            j++;
            i++;
        }    
        if(j==m) {
            cout<<"found pattern at: "<<i-j<<endl;
            j = lps[j-1];
        }    
        else if(pat[j] != text[i]) {
            if(j!=0) {
                j = lps[j-1];
            }    
            else {
                i++;
            }    
        }    
    }    
    delete[] lps;
}    

int main() {
    ios_base::sync_with_stdio(0);
    string pat = "jha";
    string text = "aditya jha";
    
    KMPSearch(pat, text);
    
    getchar();
    return 0;
}    
