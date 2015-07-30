#include <iostream>
#include <vector>

using namespace std;

	class Solution {
	public:
	    bool searchMatrix(vector<vector<int> >& matrix, int target) {
	    	if(matrix.size()==0)
				return false;
			int i=0;
			bool flag = 0;
			while(i<matrix.size()){
				if(target<matrix[i][0]){
					if(i==0)
						return false;
					flag = 1;
					break;
				}
				i++;
			}
			if(!flag){
				if(target>matrix[matrix.size()-1][matrix[matrix.size()-1].size()-1])
					return false;
			}
			vector<int> vec = matrix[i-1];
			return BinarySearch(vec,0,vec.size()-1,target);
				    
	    }
	    int BinarySearch(vector<int> nums,int start,int end,int target){
	    	if(start>end)
	    		return false;
	    	int mid = (start+end)/2;
	    	if(target == nums[mid])
	    		return true;
	    	else if(target < nums[mid])
	    		return BinarySearch(nums,start,mid-1,target);
	    	else
	    		return BinarySearch(nums,mid+1,end,target);	
	    }
	};



int main(){
	int a[] = {1,3,5,7};
	int b[] = {10,11,16,20};
	int c[] = {23,30,34,50};
	vector<int> v1(a,a+4);
	vector<int> v2(b,b+4);
	vector<int> v3(c,c+4);
	vector<vector<int> > vec;
	vec.push_back(v1);
	vec.push_back(v2);
	vec.push_back(v3);
	Solution s;
	cout<<s.searchMatrix(vec,10);
	return 0;
	
} 
