#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
    	if(nums.size()==1)
    		return nums[0];
		int i=0;
		map<int,int> m;
		while(i<nums.size()){
			if(m.find(nums[i])!=m.end())
				m[nums[i]] += 1;
			else
				m.insert(pair<int,int>(nums[i],1));
			i++;		
		}
		i = 0;
		map<int,int>::iterator iter;
		for(iter=m.begin();iter!=m.end();iter++)
			if(iter->second==1)
				return iter->first;  	    
    }
};


int main(){
	int a[] = {1,2,3,4,5,6,7,8,8,7,6,5,4,2,1};
	vector<int> v(a,a+15);
	Solution s;
	cout<<s.singleNumber(v);
	return 0;
}
