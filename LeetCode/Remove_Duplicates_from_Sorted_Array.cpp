#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==0)
        	return 0;
        int len = 1;
        
        int i=1;
        while(i<n){
        	while(nums[i]==nums[i-1])
        		i++;
			continue;
			nums[len] = nums[i];
			len++;
			i++;
        }
    	return len;
    }
};

int main() {
	int a[] = {1,1};
	vector<int> vec(a,a+2);
	Solution s;
	cout<<s.removeDuplicates(vec)<<endl;
	for(int i=0;i<vec.size();i++)
		cout<<vec[i]<<" ";
	return 0;
}
