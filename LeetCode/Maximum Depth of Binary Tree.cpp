#include <iostream>

using namespace std;

//int a[] = {2,5,2,-65535,-65535,9,-65535,-65535,0,7,-65535,0,6,-65535,-65535,-65535,-65535};
//int a[] = {1,2,-65535,-65535,3,-65535,-65535};
int a[] = {4,2,1,-65535,-65535,3,-65535,-65535,6,5,-65535,65535,7,-65535,-65535};
int n = 0;

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
    int maxDepth(TreeNode* root) {
        if(!root)
        	return 0;
        int le = maxDepth(root->left);
        int rig = maxDepth(root->right);
        
        if(le > rig)
        	return le+1;
        else
        	return rig+1;
    }
    TreeNode* Creat(){
	    if(a[n] == -65535){
	    	n++;
	    	return NULL;
	    }
	   		
	    TreeNode* root = new TreeNode(a[n++]);
	    root->left = Creat();
		root->right = Creat();
		return root; 
	}
	void PreOrder(TreeNode *t){
		if(!t)
	  		return;
		cout<<t->val<<" ";
	   	PreOrder(t->left);
	   	PreOrder(t->right);
	}

};


int main(){
	Solution s;
	TreeNode* root;
	root = s.Creat();
	s.PreOrder(root);
	cout<<endl;
	cout<<s.maxDepth(root);
	return 0;
}
