#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;


//Definition for binary tree

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
private:
	int retval;
public:    
	int maxPathSum(TreeNode *root) {
		retval = INT_MIN;
		dfs(root);
		return retval;	        
	}
	int dfs(TreeNode *t){
		if(!t)
			return 0;
		int num = t->val;
		int left_num = dfs(t->left);
		
		if(left_num > 0)
			num += left_num;

		int right_num = dfs(t->right);
		
		if(right_num > 0)
			num += right_num; 	
		retval = max(retval,num);
		
		num = max(left_num,right_num);
		return t->val+(num >0 ?num:0);
	}
};

int main(){
	return 0;
}
