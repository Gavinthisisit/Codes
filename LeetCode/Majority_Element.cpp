#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:/*
    int majorityElement(vector<int>& nums) {
    	int n = nums.size();
    	if(nums.size()==1)
			return nums[0];
		sort(nums.begin(),nums.end());
		
		int count =1;
		int i=1;
		int p = nums[0];
		while(i<nums.size()){
			if(nums[i]==p)
				count++;
			else{
				p = nums[i];
				count = 1;
			}
			if(count > n/2)
				return p;
			i++;	
		}	    
    }*/
	    int majorityElement(vector<int>& nums){
	    	int count = 0;
	    	int i=0;
	    	int retval;
	    	while(i<nums.size()){
	    		if(count==0){
	    			retval = nums[i];
	    			count = 1;
	    		}
				else{
					if(retval != nums[i])
						count--;
					else
						count++;
				}
				i++;
	    	}
	    	return retval;
	    }
};

int main(){
	int a[] = {1,2,3,2,2};
	vector<int> v(a,a+5);
	Solution s;
	cout<<s.majorityElement(v);
	return 0;
}
