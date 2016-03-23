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
int a[] = {1,2,-65535,-65535,-65535};//,4,-65535,-65535,5,-65535,6,-65535,-65535};//,2,4,3,-65535,-65535,-65535,-65535};
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
/*    void flatten(TreeNode* root) {
    	 if(!root)
		 	return;
		vector<int> vec;
		PreConstruct(root,vec);
		TreeNode* t;
		Creat(&t,vec,0);
		root = t;
		InOrder(root);   
    }*/
    void PreConstruct(TreeNode* root,vector<int>& vec){
    	if(!root)
    		return;
    	vec.push_back(root->val);
    	PreConstruct(root->left,vec);
    	PreConstruct(root->right,vec);
    }
	void Creat(TreeNode** root,vector<int> v,int i){
		if(i==v.size())
			return;
		*root = new TreeNode(v[i]);
		Creat(&((*root)->right),v,i+1);
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
	void flatten(TreeNode *root) {
        if(root == NULL) return;
	    while(root){
	        if(root->left){
	            TreeNode *pre = root->left;
	            while(pre->right)
	                pre = pre->right;
	            pre->right = root->right;
	            root->right = root->left;
	            root->left = NULL;
	        }
	        root = root->right;
	    }
    }
};



int main(){
	TreeNode* t;
	Solution s;
	s.Creat(&t);
	s.InOrder(t);
	cout<<endl;
	s.flatten(t);
	cout<<endl;
	
	return 0;
}
