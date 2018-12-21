#include<iostream>
#include<stack>
#include<utility>

using namespace std;

int main() {

    cout<<"Hello World\n";
    
    int t, n;
    stack<pair<int, int> > s;

    cin>>t;

    int firstMore[t];
    memset(firstMore, -1, sizeof(firstMore));

    for (int i=0; i<t; i++) {
        cin>>n;
        pair<int, int> p;

        while (!s.empty()) {
            if (s.top().second < n) {
                s.pop();
                continue;
            }
            firstMore[i] = s.top().first;
            break;
        }
        
        p.first = i;
        p.second = n;
        s.push(p);
    }

    return 0;
}