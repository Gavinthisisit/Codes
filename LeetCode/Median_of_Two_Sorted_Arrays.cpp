#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n)
	{
		int total = m + n;
		if (total & 0x1)
			return findKth(A, m, B, n, total / 2 + 1);
		else
			return (findKth(A, m, B, n, total / 2)
					+ findKth(A, m, B, n, total / 2 + 1)) / 2;
	}
	
	double findKth(vector<int>& a,vector<int>& b,int k){
		int m = a.size();
		int n = b.size();
		if (m > n)
			return findKth(b,a,k);
		if (m == 0)
			return b[k-1];
		if (k==1)
			return min(a[0],b[0]);
			
		int pointA = min(k/2,m);
		int pointB = k - pointA;
		if (a[pointA-1] < b[pointB-1])
			return findKth(a + pa, m - pa, b, n, k - pa);
		else if (a[pointA-1] > b[pointB-1])
			return findKth(a, m, b + pb, n - pb, k - pb);
		else
			return a[pa - 1];
	}
};

int main(){
	return 0;
}

