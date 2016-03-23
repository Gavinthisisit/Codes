#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int>& nums) {
    	vector<vector<int> > retval;
		if(nums.size() == 0)
			return retval;	
		vector<int> tmp;
		retval.clear();
		tmp.clear();
		sort(nums.begin(),nums.end());    
//		dfsSubsets(nums,tmp,0,retval);
		BitSubsets(nums,nums.size(),retval);
		return retval;
    }
    void dfsSubsets(vector<int> nums,vector<int> tmp,int level,vector<vector<int> >& retval){
    	if(level == nums.size()){
    		retval.push_back(tmp);
    		return;
    	}
    	dfsSubsets(nums,tmp,level+1,retval);
    	tmp.push_back(nums[level]);
    	dfsSubsets(nums,tmp,level+1,retval);
    }
    vector<vector<int> > Subsets(vector<int>& nums){
    	
    }
    void BitSubsets(vector<int>& nums,int n,vector<vector<int> >& retval){
    	int max = 1<<n;
    	for(int i=0;i<max;i++){
    		vector<int> tmp;
    		int idx = 0;
    		int j = i;
    		while(j>0){
    			if(j&1){
    				tmp.push_back(nums[idx]);
    			}
    			idx++;
    			j = j>>1;
    		}
    		retval.push_back(tmp);
    	}
	}
};


int main(){
	int a[] = {4,1,0};
	vector<int> vec(a,a+3);
	Solution s;
	vector<vector<int> > num;
	num = s.subsets(vec);
	for(int i=0;i<num.size();i++){
		for(int j=0;j<num[i].size();j++)
			cout<<num[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
