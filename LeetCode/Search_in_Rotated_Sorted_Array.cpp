#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
    	if(nums.size()==0)
			return -1;
		int pos = findMin(0,nums.size()-1,nums);
		int right = BinarySearch(nums,pos,nums.size()-1,target);
		int left = BinarySearch(nums,0,pos-1,target);
		
		if(right!=-1)
			return right;
		else if(left!=-1)
			return left;
		else
			return -1;  
    }
    int findMin(int left,int right,vector<int> nums){
    	if(left>right)
    		return -1;
		int mid = (left+right)/2;
    	
    	if(nums[left] <= nums[mid]){
    		int pos = findMin(mid+1,right,nums);
    		if(pos==-1)
    			return left;
    		return nums[left]<nums[pos]?left:pos;
    	}
    	else{
    		int pos = findMin(left,mid-1,nums);
    		if(pos==-1)
    			return mid;
    		return nums[mid]<nums[pos]?mid:pos;
    	}
    }
    int BinarySearch(vector<int> nums,int start,int end,int target){
    	if(start>end)
    		return -1;
    	int mid = (start+end)/2;
    	if(target == nums[mid])
    		return mid;
    	else if(target < nums[mid])
    		return BinarySearch(nums,start,mid-1,target);
    	else
    		return BinarySearch(nums,mid+1,end,target);	
    }
};

int main() {
	int a[] = {4};
	vector<int> vec(a,a+1);
	Solution s;
	cout<<s.search(vec,4);
	return 0;
}
