#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
        	return 1;
        int i = 0;
        while(i<n){
        	int p = nums[i];
        	if(nums[i]<0 || nums[i]>n || nums[i]==nums[nums[i]-1] ||nums[i]-1==i){
        		i++;
				continue;
			}
        	else
        		swap(nums[i],nums[nums[i]-1]);
        }
        for(i=0;i<n;i++){
        	int p = nums[i];
        	if(nums[i] != i+1)
        		break;
        }
        	
        return i+1;
    }
};

int main(){
	int a[] = {3,4,1,-1};
	vector<int> v(a,a+4);
	Solution s;
	cout<<s.firstMissingPositive(v);
	return 0;
}
