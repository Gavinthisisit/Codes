#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
    	if(nums.size()==0)
			return 0;
		return BinarySearch(nums,0,nums.size()-1,target);			    
    }
    int BinarySearch(vector<int> nums,int start,int end,int target){
    	if(start>nums.size()-1)
    		return nums.size();
    	if(end<0)
    		return 0;
    	if(start==end){
    		if(target>nums[start])
    			return start+1;
    		else
    			return start;
    			
    	}
    	
    	int mid = (start+end)/2;
    	if(target == nums[mid])
    		return mid;
    	else if(target < nums[mid] && target <= nums[mid-1])
    		return BinarySearch(nums,start,mid-1,target);
		else if(target <nums[mid] && target>=nums[mid-1])
			return mid;
		else if(target>nums[mid] && target>=nums[mid+1])
			return BinarySearch(nums,mid+1,end,target);
    	else if(target>nums[mid] && target<=nums[mid+1])
			return mid+1;
    		
    }
};


int main(){
	int a[] = {3,5,7,9,10};
	vector<int> vec(a,a+5);
	Solution s;
	cout<<s.searchInsert(vec,8);
	return 0; 
} 

