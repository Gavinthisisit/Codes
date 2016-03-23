#include <iostream>

using namespace std;

int a[] = {1,2,4,-65535,-65535,-65535,-65535};//5,-65535,-65535,3,6,-65535,-65535,-65535};
//int a[] = {1,2,-65535,-65535,3,-65535,-65535};
int n = 0;
//Definition for a binary tree node.
typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
}TreeNode,*BTree;


class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
    	if(root==NULL)
    		return root;
        dfsTree(root,1,root,root->left,root->right);
        return root;
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
	void dfsTree(TreeNode* Parent_root1,bool left_or_right,TreeNode* Parent_root2,TreeNode* root1,TreeNode* root2){
		if(root1==NULL && root2==NULL)
			return;
		if(root1==NULL){
			if(left_or_right){
				TreeNode* t = new TreeNode;
				t->val = root2->val;
				t->right = NULL;
				t->left = NULL;
				Parent_root1->left = t;
				Parent_root2->right = NULL;
				root1 = t;
			}
			else{
				TreeNode* t = new TreeNode;
				t->val = root2->val;
				t->right = NULL;
				t->left = NULL;
				Parent_root1->right = t;
				Parent_root2->left = NULL;
				root1 = t;
			}
		}
		else if(root2==NULL){
			if(left_or_right){
				TreeNode* t = new TreeNode;
				t->val = root1->val;
				t->right = NULL;
				t->left = NULL;
				Parent_root2->right = t;
				Parent_root1->left = NULL;
				root2 = t;
			}
			else{
				TreeNode* t = new TreeNode;
				t->val = root1->val;
				t->right = NULL;
				t->left = NULL;
				Parent_root2->left = t;
				Parent_root1->right = NULL;
				root2 = t;
			}
		}
		else{
			int tmp = root1->val;
			root1->val = root2->val;
			root2->val = tmp;
		}
		dfsTree(root1,1,root2,root1->left,root2->right);
		dfsTree(root1,0,root2,root1->right,root2->left);
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
	s.InOrder(root);
	cout<<endl;
	s.invertTree(root);
	s.InOrder(root);
	return 0;
}

