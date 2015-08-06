#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
/*    int jump(vector<int>& nums) {
    	int n = nums.size();
		if(n==0)
			return 0;
		vector<int> count;
		int i=0;
		while(i<n){
			count.push_back(65535);
			i++;
		}
		count[0] = 0;
		
		i = 0;
		while(i<n){
			int range = nums[i];
			int j=1;
			while(j<=range){
				int m1 = count[i]+1;
				int m = min(m1,count[j+i]);
				count[j+i] = m;
				if(j+i == n-1)
					return m;
				j++;	
			}
			i++;
		}
		return count[n-1];    
    }
    */
    int jump(vector<int>& nums){
    	int step = 0;
    	int max_range = 0;
    	int cur_max = 0;
		int i=0;
		while(i<nums.size()){
			if(cur_max < i){
				step++;
				cur_max = max_range;
			}
			max_range = max(max_range,nums[i]+i);
			i++;
		}
		return step; 
    }
    int max(int a,int b){
    	return a>b?a:b;
    }
};

int main(){
	int a[] = {2,1,3,1,1,4};
	vector<int> v(a,a+6);
	Solution s;
	cout<<s.jump(v);
	return 0;
}
