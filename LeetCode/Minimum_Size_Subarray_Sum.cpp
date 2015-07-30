#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
    	int n = nums.size();
    	if(n==0)
    		return 0;
    	int sum = 0;
		int retval = n+1;
		int start = 0;
		int end = 0;
		while(start<n && end<n){
			while(sum<s && end<n){
				sum += nums[end];
				end++;
			}
			while(sum>=s && start<end){
				if(retval > (end-start))
					retval = (end-start);
				sum -= nums[start];
				start++;
			}
		}
		return retval==n+1?0:retval;    
    }
};


int main(){
	int a[] = {4,2,3,2,2,4,2,1};
	vector<int> vec(a,a+8);
	Solution s;
	cout<<s.minSubArrayLen(7,vec);
	return 0;
}
