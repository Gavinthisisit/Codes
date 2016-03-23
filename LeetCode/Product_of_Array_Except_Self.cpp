#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    	long long int val = 1;
    	int count = 0;
		for(int i=0;i<nums.size();i++){
			if(count>1){
				val=0;
				break;
			}
			if(nums[i]==0){
				count++;
				continue;
			}
			val = val*nums[i];
		}
			
		vector<int> retval;
		for(int i=0;i<nums.size();i++){
			int t = nums[i];
			int tmp;
			if(count==1){
				if(t==0)
					retval.push_back(val);
				else
					retval.push_back(0);
			}
			else if(count>1){
				retval.push_back(0);
			}
			else
				retval.push_back(val/t);
		}
		return retval;    
    }
};

int main(){
	int a[] = {0,0};
	vector<int> vec(a,a+2);
	vector<int> ret;
	Solution s;
	ret = s.productExceptSelf(vec);
	for(int i=0;i<ret.size();i++)
		cout<<ret[i]<<" ";
	return 0;
}
