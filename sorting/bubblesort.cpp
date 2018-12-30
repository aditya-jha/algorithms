//
// Created by Aditya Jha on 2018-12-30.
//

#include<iostream>

using namespace std;

void swap(int *a, int i, int j) {
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}

void bubble_sort(int *a, int n) {
    for (int i=0;i<n;i++) {
        for (int j=0; j<n; j++) {
            if (a[i] < a[j]) {
                swap(a, i, j);
            }
        }
    }
}

int main() {
    int a[] = {2,4,3,8,6,10,9,7,1,5};
    int n = sizeof(a)/sizeof(int);

    for(int i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;

    bubble_sort(a, n);

    for(int i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;

    return 0;
}