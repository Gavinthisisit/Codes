#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    	int i,j;
		i = m-1;
		j = n-1;
		int k = 1;
		while(i>=0 && j>=0){
			if(nums1[i] >= nums2[j]){
				nums1[m+n-k] = nums1[i];
				k++;
				i--;
			}
			else{
				nums1[m+n-k] = nums2[j];
				k++;
				j--;
			}
		}
		while(i>=0){
			nums1[m+n-k] = nums1[i];
			k++;
			i--;
		}
		while(j>=0){
			nums1[m+n-k] = nums2[j];
			k++;
			j--;
		}
			
    }
};


int main(){
	int a[] = {1,3,3,4,5};
	
	int b[] = {2,2,4,5,7};
	
	vector<int> nums1;
	
	for(int i=0;i<20;i++){
		if(i<5)
			nums1.push_back(a[i]);
		else
			nums1.push_back(-65535);
	}
	vector<int> nums2(b,b+5);
	
	Solution s;
	
	s.merge(nums1,5,nums2,5);
	
	int i = 0;
	
	while(i<10)
		cout<<nums1[i++]<<" ";
	cout<<endl;

	return 0;
}
