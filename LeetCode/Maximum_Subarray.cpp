#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
    	int n = nums.size();
    	if(n==0)
    		return 0;
    	else if(n==1)
    		return nums[0];
    	int max = -65535;
    	int cur_max = 0;
		int start = 0;
		int end = 0;
		int left=0,right=0;
		for(int i=0;i<nums.size();i++){
			cur_max += nums[i];
			
			if(cur_max > 0){
				right = i;
				if(cur_max > max){
					max = cur_max;
					start = left;
					end = right;
				}
			}
			else{
				if(cur_max > max)
					max = cur_max;
				cur_max = 0;
				left = right = i+1;
			}
		} 
		return max;   
    }
};



int main(){
	int a[] = {-2,-1};
	vector<int> vec(a,a+2);
	Solution s;
	cout<<s.maxSubArray(vec);
	return 0;
}
