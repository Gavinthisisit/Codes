#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	 int n = nums.size();
		 if(n==0)
		 	return;
		 
		 int pos = -1;
		 int i = n-1;
		 while(i>0){
		 	if(nums[i] > nums[i-1]){
		 		pos = i-1;
		 		break;
		 	}
		 	i--;
		 }
		 if(pos==-1){
		 	reverse(nums,0,nums.size()-1);
		 	return;
		 }
		 i = pos;
		 int end = pos+1;
		 int min = nums[i+1];
		 while(i<n){
		 	if(nums[i] <=min && nums[i] > nums[pos]){
		 		min = nums[i];
		 		end = i;
		 	}
			 i++;	
		 }
		 int tmp = nums[pos];
		 nums[pos] = nums[end];
		 nums[end] = tmp;
		 
		 reverse(nums,pos+1,n-1);		 

    }
	void reverse(vector<int>& vec,int start,int end){  
		 int k = 0;
		 int n = (end-start+1)/2;
		 while(k<n){
		 	int tmp = vec[start+k];
		 	vec[k+start] = vec[end-k];
		 	vec[end-k] = tmp;
		 	k++;
		 } 
	}  
};

int main(){	
	int a[] = {2,3,1,3,3};
	vector<int> v(a,a+5);
	Solution s;
	s.nextPermutation(v);
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	return 0;
} 
