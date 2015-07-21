#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
    	int n = nums.size();
		
		int i=0;
		int end0,end1;
		end0 = end1 = -1;
		while(i<n){
			int tmp = nums[i];
			nums[i] = 2;
			
			if(tmp==0){
				nums[++end1] = 1;
				nums[++end0] = 0;
			} 
			if(tmp==1){
				nums[++end1] = 1;
			}
			i++;
		}    
    }
};



int main(){
	int a[] = {0,1,2,0,2,1};
	vector<int> v(a,a+6);
	Solution s;
	s.sortColors(v);
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	return 0;
} 
