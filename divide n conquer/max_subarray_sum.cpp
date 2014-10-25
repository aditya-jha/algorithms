#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<climits>

using namespace std;

int max(int a, int b, int c) {
    return max(max(a,b),c);
}    

int maxCrossingSum(int a[], int low, int mid, int high) {
    int sum=0,left_sum = INT_MIN, right_sum = INT_MIN;
    
    for(int i=mid;i>=low;i--) {
        sum += a[i];
        if(left_sum<sum) left_sum = sum;
    }    
    
    sum = 0;
    for(int i=mid+1;i<=high;i++) {
        sum += a[i];
        if(sum>right_sum) {
            right_sum = sum;
        }    
    }    
    
    return left_sum + right_sum;
}    

int maxSubArraySum(int a[], int low, int high) {
    if(low == high) return a[low];
    
    int mid = (low+high)/2;
    
    return max(maxSubArraySum(a, low, mid),
                maxSubArraySum(a, mid+1, high),
                maxCrossingSum(a, low, mid, high));
}    

int main() {
    int arr[] = {2, 3, 4, 5, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    int max_sum = maxSubArraySum(arr, 0, n-1);
    
    printf("Maximum contiguous sum is %d\n", max_sum);
    
    getchar();
    return 0;
}    
