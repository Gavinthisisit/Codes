#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
        	return 0;
        int len = 0;
        
        int i=0;
        while(i<n){
        	int count = 0;
        	while(nums[i]==nums[i+1]){
        		if(count<2){
        			nums[len] = nums[i];
        			len++;
        		}
        		count++;
				i++;
        	}
        	if(i<n){
        		if(count<2){
        			nums[len] = nums[i];
        			len++;	
        		}
				i++;
        	}
        }
    	return len;
    }
};

int main() {
	int a[] = {1};
	vector<int> vec(a,a+1);
	Solution s;
	cout<<s.removeDuplicates(vec)<<endl;
	for(int i=0;i<vec.size();i++)
		cout<<vec[i]<<" ";
	return 0;
}
