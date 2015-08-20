#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
    	int max,left,right,retval;
		if(height.size()<2)
			return 0;
		left=0;
		right = height.size()-1;
		max = 0;
		retval = 0;
		while(left<right){
			max = min(height[left],height[right])*(right-left);
			if(max>retval)
				retval = max;
			if(height[left] <height[right])
				left++;
			else
				right--; 
		}
		return retval;	    
    }
    int min(int a,int b){
    	return a<b?a:b;
    }
};

int main(){
	int a[] = {1,3,2,5,3,6};
	vector<int> vc(a,a+6);
	Solution s;
	cout<<s.maxArea(vc);
	return 0;
} 
