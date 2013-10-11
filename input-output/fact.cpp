    #include<iostream>
    using namespace std;
     
    int fact[200] = {0}, index=0;
     
    void factorial(int n) {
    int p=n-1, carry=0, digit=0, i=0, m=0;
    while(i<index) {
    m=fact[i]*p + carry;
    digit = m%10;
    carry = m/10;
    fact[i] = digit;
    i++;
    }
    while(carry!=0) {
    digit = carry%10;
    carry = carry/10;
    fact[index] = digit;
    index++;
    }
    if(p>1) factorial(p);
    else {
    for(int i=index-1; i>=0; i--) cout<<fact[i];
    cout<<endl;
    }
    }
     
    int main() {
    int t,n,c;
    cin>>t;
    while(t>0) {
    cin>>n;
    if(n==0 or n==1) cout<<"1"<<endl;
    else {
    c=n;
    index=0;
    while(c!=0) {
    fact[index] = c%10;
    c=c/10;
    index++;
    }
    //for(int i=0;i<index;i++) cout<<fact[i]<<" ";
    factorial(n);
    }
    t--;
    }
    // system("pause");
    return 0;
    } 
