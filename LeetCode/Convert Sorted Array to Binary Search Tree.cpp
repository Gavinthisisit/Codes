#include <iostream>
#include <vector>

using namespace std;


/**
 * Definition for a binary tree node.
**/
struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
int pos;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    	TreeNode* root = NULL;
    	int len = nums.size();
    	if(len == 0)
    		return root;
		pos = 0;
    	root = buildTree(nums,0,len-1);
        return root;
    }
    TreeNode* buildTree(vector<int> nums,int start,int end){
		if(start > end)
			return NULL;
		int mid = start+ (end-start)/2;
		TreeNode* left = buildTree(nums,start,mid-1);
		TreeNode* root = new TreeNode(nums[pos]);
		root->left = left;
		pos += 1;
		root->right = buildTree(nums,mid+1,end);
		return root;
    }
    void PreOrder(TreeNode* t){
		if(!t)
			return ;
		cout<<t->val<<" ";
		PreOrder(t->left);
		PreOrder(t->right);
	}
};

int main(){
	int a[] = {1,2,3,4,5,6};
	vector<int> vec;
	Solution s;
	TreeNode* root;
	root = s.sortedArrayToBST(vec);
	s.PreOrder(root);
	cout<<endl;
	return 0;
}
