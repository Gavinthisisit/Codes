#include <iostream>
#include <vector>
#include <stack>

using namespace std;


class Solution{
public:
	int largestRectangleArea(vector<int>& height) {
		height.push_back(0); 
    	int n = height.size();
		int maxArea = 0;
		int i = 0;
		stack<int> stk;
		while(i<n){
			if(stk.empty() || height[stk.top()] <= height[i]){
				stk.push(i++);	
			}
			else{
				int p = stk.top();
				stk.pop();
				maxArea = max(maxArea,height[p]*(stk.empty()?i:i-stk.top()-1));
			}
		} 
		return maxArea;   
    }
	int max(int a,int b){
		return a>b?a:b;
	}		
};



int main(){
	int a[] = {2,1,5,6,2,3};
	vector<int> vec(a,a+6);
	Solution s;
	cout<<s.largestRectangleArea(vec);
	return 0;
}
