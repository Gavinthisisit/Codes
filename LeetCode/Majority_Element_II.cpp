#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
    	int n = nums.size();
    	vector<int> retval;
		if(n==0)
			return retval; 
		map<int,int> mm;
		for(int i=0;i<n;i++){
			map<int,int>::iterator l_it;
			l_it = mm.find(nums[i]);
			if(l_it == mm.end()){
				mm.insert(pair<int,int>(nums[i],1));
			}
			else{
				mm[nums[i]] += 1;
			}
		}
		map<int,int>::iterator l_it;
		for(l_it=mm.begin();l_it!=mm.end();l_it++){
			if(l_it->second > n/3)
				retval.push_back(l_it->first);
		}
		
		return retval;    
    }
};


int main(){
	int a[] = {1,2};
	vector<int> v(a,a+2);
	Solution s;
	vector<int> t = s.majorityElement(v);
	for(int i=0;i<t.size();i++)
		cout<<t[i]<<" "; 
	return 0;
	
} 
