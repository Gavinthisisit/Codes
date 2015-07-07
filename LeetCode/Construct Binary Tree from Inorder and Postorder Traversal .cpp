#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
};

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    	if(inorder.size()==0 || inorder.size()!=postorder.size())
    		return NULL;
       	else if(inorder.size()==1){
       		TreeNode* ret = new TreeNode;
			ret->val = inorder[0];
			ret->left = NULL;
			ret->right = NULL;
			return ret;
       	}
       	return  buildTree_dfs(0,inorder.size()-1,0,postorder.size()-1,inorder,postorder); 
    }
    TreeNode* buildTree_dfs(int in_start,int in_end,int post_start,int post_end,vector<int>& inorder,vector<int>& postorder){
    	if(in_start > in_end || in_start < 0  || in_end < 0)
    		return NULL;
		if(post_start > post_end || post_start < 0  || post_end < 0)
    		return NULL;
    	TreeNode* root = new TreeNode;
    	root->val = postorder[post_end];
    	
    	int pos = 0;
    	for(int i=in_start;i<=in_end;i++)
    		if(inorder[i] == postorder[post_end]){
				pos = i;
				break;		
    		}

    	root->left = buildTree_dfs(in_start,pos-1,post_start,post_start+pos-1-in_start,inorder,postorder);
    	root->right = buildTree_dfs(pos+1,in_end,post_start+pos-in_start,post_end-1,inorder,postorder);
    	return root;
    }
};


/*先序遍历*/
void PreOrderTraverse(TreeNode* T)
{
	/*树为空时结束遍历*/
	if (T)
	{
		cout<<T->val<<" ";

		PreOrderTraverse(T->left);

		PreOrderTraverse(T->right);
	}
}

/*中序遍历*/
void InOrderTraverse(TreeNode* T)
{
	if(T)
	{
		InOrderTraverse(T->left);

		cout<<T->val<<" ";

		InOrderTraverse(T->right);
	}
}

/*后序遍历*/
void PosOrderTraverse(TreeNode* T)
{
	if (T)
	{
		PosOrderTraverse(T->left);

		PosOrderTraverse(T->right);

		cout<<T->val<<" ";
	}
}


int main(){
	int a[] = {1,2,3,4};
	int b[] = {4,3,2,1};
	vector<int> in(a,a+4);
	vector<int> post(b,b+4);
	Solution s;
	TreeNode* tree;
	tree = s.buildTree(in,post);
	PreOrderTraverse(tree);
	return 0;
}
