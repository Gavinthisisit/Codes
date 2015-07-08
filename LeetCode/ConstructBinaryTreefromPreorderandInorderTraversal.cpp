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

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len1 = preorder.size();
        int len2 = preorder.size();
        TreeNode* root = NULL;
        if(len1!=len2 ||len1==0||len2 == 0)
        	return root;
        root = dfsBuild(preorder,inorder,0,len1-1,0,len2-1);
        return root;
    }
    TreeNode* dfsBuild(vector<int>& preorder,vector<int>& inorder,int pre_start,int pre_end,int in_start,int in_end){
		if(pre_start > pre_end || pre_start<0 ||pre_end<0)
			return NULL;
		if(in_start > in_end || in_start<0 ||in_end <0)
			return NULL;
		int value = preorder[pre_start];
		int i = in_start;
		int pos = 0;
		while(i<=in_end){
			if(inorder[i] == value){
				pos = i;
				break;
			}
			i++;
		}
		TreeNode* root = new TreeNode(value);
		root->left = dfsBuild(preorder,inorder,pre_start+1,pre_start+pos,in_start,in_start+pos-1);
		root->right = dfsBuild(preorder,inorder,pre_start+1+pos,pre_end,in_start+pos+1,in_end);	
		return root;
	}
	void PostOrder(TreeNode* t){
		if(!t)
			return;
		PostOrder(t->left);
		PostOrder(t->right);
		cout<<t->val<<" "; 
	}
};


int main(){
	int a[] = {1,2,4,5,3,6};
	int b[] = {4,2,5,1,6,3};
	vector<int> pre(a,a+6);
	vector<int> in(b,b+6);
	Solution s;
	TreeNode* root;
	root = s.buildTree(pre,in);
	s.PostOrder(root);
	return 0;
}
