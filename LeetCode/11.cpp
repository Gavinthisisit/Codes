#include <iostream>
#include <vector>

using namespace std;

class Solution_Brute {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int i=0,j=0,k=0;
		double C[100];
		while(i<m && j<n){
			if(A[i]<B[j])
				C[k++] = A[i++];
			else
				C[k++] = B[j++];
		}
		while(i<m)
			C[k++] = A[i++];
		while(j<n)
			C[k++] = B[j++];
		int x = (m+n-1)%2;
		int y = (m+n-1)/2;
		cout<<y<<endl;
/*		for(i=0;i<m+n;i++)
			cout<<C[i]<<" ";
		cout<<endl;*/
		if(x){
			return (double)(C[y]+C[y+1])/2.0;
		}
		else
			return C[y];
    }
};
/*
class Solution {
public: 
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int i=0,j=0,k=0;
		double retval;
		int high_bound,low_bound;
		high_bound = 9999;
		low_bound = -9999;
		bool flag = false;
		int midA,midB;
		while(!flag){
			midA = A[(m-1)/2];
			if(midA>low_bound && midA<high_bound){
				int t = m-1-(m-1)/2;
				if(B[t]>=midA && B[t-1]<=midA){
					falg = true;
					retval = midA;
				}
				else if(B[t]<miaA)
					high_bound = midA;
				else if(B[t-1]>midA)
					low_bound = midA;
			}
		}
    }
};*/

class Solution{
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int i,j;
		double midA,midB;
		int x,y;
		bool flag = false;
		while(!flag){
			x = (m-1)/2;
			y = (n-1)/2;
			if((m-1)%2)
				midA = (A[x]+A[x+1])/2;
			else
				midA = A[x];
			if((n-1)%2)
				midB = (B[y]+B[y+1])/2;
			else
				midB = B[y];
			if(midA<midB){
				n = y+1;
			}
			else if(midA>midB){
				m = x+1;	
			}
			else{
				flag = true;
				retval = midA;
			}
		}



	}
};




int main(){
	int a[] = {-2,1,3,3,5,7,8,9};
	int b[] = {-1,1,2,3,4,5,8,45};
//	vector<int> num;
//	for(int i=0;i<8;i++)
//		num.push_back(a[i]);
	Solution_Brute s = Solution_Brute();
//	vector<int> idx;
	double idx;
	idx = s.findMedianSortedArrays(a,8,b,8);
	cout<<idx<<endl;
/*	for(i=0;i<2;i++)
		cout<<idx.at(i)<<" ";
	cout<<endl;*/
	
	
	return 0;
}
abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!\"#$%&'()*+,-./:;<=>?@[\]^_`{|}~