#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

#define max(a,b) (a>b?a:b)

int LCS(string a, string b) {
	//cout << a.length() << "  " << b.length() << endl;
	int dp[a.length()+1][b.length()+1];

	for(int i=0;i<=a.length();i++) dp[i][0] = 0;
	for(int i=0;i<=b.length();i++) dp[0][i] = 0;

	for(int i=1;i<=a.length();i++) {
		for(int j=1;j<=b.length();j++) {
			if(a[i-1]==b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			
			//cout << a[i-1] << "  " << b[j-1] << dp[i][j] << endl;
		}
	}
	
	for(int i=0;i<=a.length();i++) {
		for(int j=0;j<=b.length();j++) cout << 	dp[i][j] << " ";
		cout << endl;
	}

	int i=a.length(),j=b.length();
	
	while(i>0 and j>0) {
		if(dp[i-1][j-1] == dp[i][j]) { i--; j--; }
		else {
			cout << a[i-1];
			i--; j--;
		}
	}	
	cout << endl;

	return dp[a.length()][b.length()];
}

int main() {
	string a,b;
	cin >> a >> b;
	
	cout << "The length of LCS is: " << LCS(a,b) << endl;
	
	return 0;
}
