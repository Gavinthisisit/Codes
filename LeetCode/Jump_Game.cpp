#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
    	bool flag = 1;
    	
    	int n = nums.size();
    	if(n==0)
    		return 0;
		int count = 1;
		int i = n-2;
		
		while(i>=0){
			if(nums[i]==0){
				if(flag){
					count += 1;
					flag = 0;
				}
				else
					count++;
			}
			else{
				if(flag==1){
					i--;
					continue;
				}
				else{
					if(nums[i] >= count){
						count = 1;
						flag = 1;
					}
					else
						count++;
				}
			}
			i--;
		} 
		return flag;	    
    }
};

int main(){
	int a[] = {3,0,1,2,1,0,4};
	vector<int> v(a,a+7);
	Solution s;
	cout<<s.canJump(v);
	return 0;
}
