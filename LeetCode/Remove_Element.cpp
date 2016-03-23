#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    	int n = nums.size();
		if(n==0)
			return 0;
		int p = n-1;
		while(p>=0 &&nums[p]==val)
			p--;
		for(int i=0;i<=p;i++){
			if(nums[i]==val){
				while(nums[p] == val)
					p--;
				if(p>i)
					nums[i] = nums[p--];
			}
		}
		return p+1;    
    }
};


int main(){
	int a[] = {2,2,3};
	vector<int> vec(a,a+3);
	Solution s;
	cout<<s.removeElement(vec,2);
	return 0;
}
