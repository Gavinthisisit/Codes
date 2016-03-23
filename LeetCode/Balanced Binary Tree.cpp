#include <iostream>

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
int a[] = {1,-65535,2,-65535,3,-65535,-65535};//,2,4,3,-65535,-65535,-65535,-65535};
//int a[] = {1,2,-65535,-65535,3,-65535,-65535};
int n = 0;
bool quit_flag;
 

typedef struct TreeNode{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
}TreeNode,*BTree;
 
 
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        quit_flag = 0;
        if(!root)
        	return true;
        countDeepth(root);
        if(quit_flag)
        	return false;
        else
        	return true;
    }
    int countDeepth(TreeNode* t){
    	if(quit_flag)
    		return 0;
    	if(!t)
			return 0;
		int left_deep = countDeepth(t->left);
		int right_deep = countDeepth(t->right);
		int tmp = left_deep - right_deep;
		if(tmp >= 2 || tmp <= -2){
			quit_flag = 1;
			return 0;
		}
		return tmp>0?1+left_deep:1+right_deep;	
    }
    void Creat(BTree *root){
	    if(a[n] == -65535){
	    	*root = NULL;
	    	n++;
	    	return;
	    }
	   		
	    *root = new TreeNode(a[n++]);
//	   	(*root)->val = a[n++];
	    Creat(&((*root)->left));
		Creat(&((*root)->right)); 
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
	TreeNode* t;
	Solution s;
	s.Creat(&t);
	s.InOrder(t);
	cout<<endl;
	cout<<s.isBalanced(t)<<endl;
	return 0;
}
