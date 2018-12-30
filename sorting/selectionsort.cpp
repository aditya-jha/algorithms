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

void selection_sort(int *a, int n) {
    for (int i=0; i<n;i++) {
        int min = i;
        for (int j=i;j<n;j++) {
            if (a[j] < a[i]) {
                min = j;
            }
        }
        swap(a, i, min);
    }
}

int main() {
    int a[] = {2,4,3,8,6,10,9,7,1,5};
    int n = sizeof(a)/sizeof(int);

    for(int i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;

    selection_sort(a, n);

    for(int i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<endl;

    return 0;
}