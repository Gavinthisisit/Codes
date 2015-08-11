#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
    	int n = nums.size();
    	if(n==0 || n==1)
    		return 0;
    	int i=0;
    	while(i<n){
			if(i==0){
    			if(nums[i]>nums[i+1])
    				return i;
			}
			else if(i==n-1){
    			if(nums[i]>nums[i-1])
    				return i;
			}
			else{
    			if(nums[i]>nums[i-1] && nums[i]>nums[i+1])
					return i;
			}
			i++;
    	}
    }
};
int main(){
	int a[] = {-2147483648};
	vector<int> v(a,a+1);
	Solution s;
	cout<<s.findPeakElement(v);
	return 0;
}
