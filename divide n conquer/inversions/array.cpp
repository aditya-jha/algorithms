#include<iostream>
using namespace std;

int n; 

long long int countMergeInversions(int A[],int p,int q,int r);
long long int countInversions(int A[], int p, int r);

int main() {
	cout<<"Enter n: ";
	cin>>n;
	
	int A[n];
	cout<<"Enter "<<n<<" intergers: ";
	
	for(int i=0; i<n; i++) cin>>A[i];
	
	cout<<"The number of Inversions are: "<<countInversions(A,0,n-1)<<endl;	

	//system("pause");
	return 0;
}


long long int countInversions(int A[], int p, int r) {

	if(p>=r) return 0; 

	long long int x=0,y=0,z=0;
	int q = (p+r)/2;
//	cout<<"q: "<<q<<endl;
	x = countInversions(A,p,q);
	y = countInversions(A,q+1,r);
	z = countMergeInversions(A,p,q,r);

	return x+y+z;
	
}

long long int countMergeInversions(int A[],int p,int q,int r) {
	long long int count = 0;
	int left_length = q-p+1, right_length = r-q;

	//cout<<"left_length: "<<left_length<<endl;
	//cout<<"right_length: "<<right_length<<endl;

	int i=0, j=0, k=0;
	int left[left_length], right[right_length];

	for(i=0,j=p; i<left_length; i++, j++) left[i] = A[j];

	for(i=0,j=q+1; i<right_length; i++, j++) right[i] = A[j];
	

	i=0, j=0;	
	for(int k=p; k<=r; k++) {
		if(i != left_length and j != right_length) {
			if(left[i] < right[j]) {
				A[k] = left[i];
				i++;
			} else {
				A[k] = right[j];
				j++;
				count += left_length - i;
			}
		} else {
			if(i == left_length) {
				A[k] = right[j];
				j++;
				//count += left_length - i;
			} else {
				A[k] = left[i];
				i++;
			}
		}
	}
		
	//for(int k=p; k<=r; k++) cout<<A[k]<<" ";
	
	return count;
}


