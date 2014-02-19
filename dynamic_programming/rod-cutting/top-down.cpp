#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int price[] = {0,1,5,8,9};
int cost[5] = {0};

int maxProfit(int n) {
	if(cost[n]>0) return cost[n];
	
	if(n==0) return 0;	
	
	int q = -1;
	for(int i=1;i<=n;i++) {
		q = max(q,maxProfit(n-i)+price[i]);
	}
	
    cost[n]=q;
	return q;
}


int main() {
	cost[1] = price[1];
	cout<<maxProfit(4)<<endl;
	for(int i=0;i<5;i++) cout<<cost[i]<<" ";
	return 0;	
}
