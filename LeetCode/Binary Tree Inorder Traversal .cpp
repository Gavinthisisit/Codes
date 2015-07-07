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
 
 int a[] = {2,5,2,-65535,-65535,9,-65535,-65535,0,7,4,-65535,-65535,0,6,-65535,-65535,-65535,-65535};
//int a[] = {1,2,-65535,-65535,3,-65535,-65535};
int n = 0;
 
 typedef struct TreeNode{
 	int val;
 	TreeNode* left;
	TreeNode* right;
 }TreeNode,*TNode;
 
 
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
    	vector<int> retval;
		if(root == NULL)
			return retval;
		InOrder(root,retval);
		return retval;		    
    }
	void Creat(TNode *root){
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
	void InOrder(TreeNode *t,vector<int>& retval){
	   	if(!t)
	  		return;
	   	InOrder(t->left,retval);
	   	retval.push_back(t->val);
	   	InOrder(t->right,retval);
	}
};

int main(){
	Solution s;
	TreeNode* root;
	s.Creat(&root);
	vector<int> ret;
	s.InOrder(root,ret);
	for(int i=0;i<ret.size();i++)
			cout<<ret[i]<<" ";
	cout<<endl;
/*	int a[] = {1,2,3,4};
	vector<int> v1(a,a+4);
	vector<int> v2;
	v2 = v1;
	for(int i=0;i<v2.size();i++)
			cout<<v2[i]<<" ";
	cout<<endl;*/
	return 0;
}


