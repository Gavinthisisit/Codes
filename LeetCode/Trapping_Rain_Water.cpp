#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
    	int left = 0;
		int right = height.size()-1;
		int secHeight = 0;
		int retval = 0;
		while(left<right){
			if(height[left] < height[right]){
				secHeight = max(height[left],secHeight);
				retval += secHeight-height[left];
				left++;
			}
			else{
				secHeight = max(secHeight,height[right]);
				retval += secHeight-height[right];
				right--;
			}
		}
		return retval;    
    }
};


int main(){
	int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
	vector<int> vec(a,a+12);
	Solution s;
	cout<<s.trap(vec);
	return 0;
		
}
