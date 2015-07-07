#include <iostream>

using namespace std;

int a[] = {1,2,3,-65535,-65535,3,-65535,-65535,2,4,-65535,-65535,3,-65535,-65535};
//int a[] = {1,2,-65535,-65535,3,-65535,-65535};
int n = 0;
bool quit_flag;
//Definition for a binary tree node.
typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
}TreeNode,*BTree;


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
    	quit_flag = true;
    	if(root==NULL)
    		return true;
        return dfsTree(root->left,root->right);
    }
    void Creat(BTree *root){
	    if(a[n] == -65535){
	    	*root = NULL;
	    	n++;
	    	return;
	    }
	   		
	    *root = new TreeNode;
	   	(*root)->val = a[n++];
	    Creat(&((*root)->left));
		Creat(&((*root)->right)); 
	}
	bool dfsTree(TreeNode* root1,TreeNode* root2){
		if(!quit_flag)
			return false;
		if(root1==NULL && root2==NULL)
			return true;
		if(root1==NULL || root2==NULL)
			return false;
			
			if(root1->val == root2->val && quit_flag){
				bool flag = dfsTree(root1->left,root2->right) && dfsTree(root1->right,root2->left);
				if(flag)
					return true;
				else{
					quit_flag = false;
					return false;
				}		
			}
			else
				return false;
	}
	void InOrder(TreeNode *t){
	   	if(!t)
	  		return;
	   	InOrder(t->left);
	   	cout<<t->val<<" ";
	   	InOrder(t->right);
	}
};



int main(){
	Solution s;
	TreeNode* root;
	s.Creat(&root);
//	s.InOrder(root);
	cout<<s.isSymmetric(root)<<endl;
	return 0;
}
