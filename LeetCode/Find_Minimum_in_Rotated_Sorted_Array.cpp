#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
    	int n = nums.size();
		if(n==0)
			return 0;
		if(n==1)
			return nums[0];
		return dfsFind(nums,0,n-1);	    
    }
    int dfsFind(vector<int>& vec,int start,int end){
    	if(end-start==1)
    		return min(vec[start],vec[end]);
		else if(start==end)
			return vec[start];
    	int mid = (end+start)/2;
    	if(vec[start] < vec[mid])
    		return min(vec[start],dfsFind(vec,mid+1,end));
    	else
    		return min(dfsFind(vec,start,mid-1),vec[mid]);
    }
    int min(int a,int b){
    	return a<b?a:b;
    }
};


int main(){
	int a[] = {4,5,6,7,0};
	vector<int> v(a,a+7);
	Solution s;
	cout<<s.findMin(v);
	return 0;
}

