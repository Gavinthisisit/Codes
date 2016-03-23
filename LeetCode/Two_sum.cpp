#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node{
	int value;
	int pos;
};

bool cmp(Node a,Node b){
	return a.value<b.value;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	vector<int> retval;
		vector<Node> list;
		
		for(int i=0;i<nums.size();i++){
			Node tmp;
			tmp.value = nums[i];
			tmp.pos = i;
			list.push_back(tmp);
		}    
		sort(list.begin(),list.end(),cmp);
		int left = 0,right = nums.size()-1;
		while(left < right){
			int sum = list[left].value+list[right].value;
			if(sum==target){
				if(list[left].pos < list[right].pos){
					retval.push_back(list[left].pos+1);
					retval.push_back(list[right].pos+1);
				}
				else{
					retval.push_back(list[right].pos+1);
					retval.push_back(list[left].pos+1);
				}
				left++;
				right--;
					
			}
			else if(sum < target)
				left++;
			else
				right--;
		}
		return retval;
    }
};

int main(){
	int a[] = {2,7,11,15};
	vector<int> v(a,a+4);
	Solution s;
	vector<int> t = s.twoSum(v,9);
	int n = t.size();
	for(int i=0;i<n;i++)
		cout<<t[i]<<" ";
	return 0;
	
} 
