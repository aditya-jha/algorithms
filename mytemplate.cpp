#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <queue>
#include <utility>
#include <cmath>
#include <climits>

using namespace std;

#define MOD 1000000007
#define ld long
#define lu long unsigned 
#define llu long long unsigned
#define lld long long
#define INF -1

#define maxm(a,b) (a>b?a:b)
#define minm(a,b) (a<b?a:b)
#define REP(a) for(int i=0;i<a;i++)
#define REPR(a,b) for(int i=a;i<b;i++)
#define pb(a) push_back(a)
#define mk(a,b) make_pair(a,b)
#define DEBUG(a) cout<<a<<" "

const llu maxn = 1e19;

int main() {
	ios_base::sync_with_stdio(0);
	
	vector<int> v;
	v.pb(1);
	DEBUG(v[0]);	
	cout<<maxn<<endl;
		
	REP(5) cout<<i<<" ";
	cout<<endl;
	
	REPR(5,6) cout<<i<<" ";
	cout<<endl;	
	return 0;
}
