#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(int nums[], int n, int k) {		
    	int i;
    	int tmp[100000];
    	for(i=0;i<n;i++){
    		int pos = (i+k)%n;
    		tmp[pos] = nums[i];
    	}
    	for(i=0;i<n;i++){
    		nums[i] = tmp[i];
    	}
    }
};


int main(){
	
	int a[] = {1,2,3,4,5,6,7};
	Solution s;
	s.rotate(a,7,3);
	for(int i=0;i<7;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
