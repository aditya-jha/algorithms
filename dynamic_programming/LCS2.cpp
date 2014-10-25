#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int LCS(string a, string b, int n, int m) {
    int dp[n+1][m+1];
    
    for(int i=0;i<=n;i++) {
        for(int j=0;j<=m;j++) {
            if(i==0 || j==0) dp[i][j] = 0;
            
            else if(a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            
            else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }    
    }    
    
    int index = dp[n][m];
    int i=n,j=m;
    char c[index+1];
    c[index] = '\0';
    
    while(i>0 and j>0) {
        if(a[i-1] == b[j-1]) {
            c[--index] = a[--i];
            j--;
        }    
        else if(dp[i-1][j] > dp[i][j-1]) i--;
        else j--;
    }    
    
    cout<<c<<endl;
    
    return dp[n][m];
}

int main() {
    ios_base::sync_with_stdio(0);
    
    string a,b;
    cin>>a>>b;
    
    cout<<LCS(a,b,a.length(),b.length())<<endl;
    
    system("pause");
    return 0;    
}    
