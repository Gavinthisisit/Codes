#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> retval;
        if(nums.size()==0)
        	return retval;
        int pre = nums[0];
        string s = int2str(pre);
        string tmp = s;
        int flag = 0;
        for(int i=1;i<nums.size();i++){
        	if(nums[i]==pre+1){
        		flag++;
        		pre = nums[i];
				continue;	
        	}
        	else if(nums[i]>pre+1){
        		if(flag){
        			s = int2str(pre);
        			tmp+="->"+s;
        		}
        		retval.push_back(tmp);
        		pre = nums[i];
        		s = int2str(pre);
        		tmp = s;
        		flag = 0;
        	}
        }
        if(flag){
        	s = int2str(pre);
        	tmp+="->"+s;
        }
        retval.push_back(tmp);
        return retval;
	}
	string int2str(int n) {
	
	    char t[256];
		string s;
		sprintf(t,"%d",n);
    	s = t;
		return s;
	}
};


int main(){
	int a[] = {0,1,2,4,5,7};
	vector<int> v(a,a+6);
	vector<string> vec;
	Solution s;
	vec = s.summaryRanges(v);
	for(int i=0;i<vec.size();i++)
		cout<<vec[i]<<" ";

	return 0;
}
