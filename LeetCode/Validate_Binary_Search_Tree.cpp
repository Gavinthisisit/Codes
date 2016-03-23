#include <iostream>
#include <vector>

using namespace std;

int a[] = {4,2,1,-65535,-65535,3,-65535,-65535,6,5,-65535,65535,7,-65535,-65535};
//int a[] = {1,2,-65535,-65535,3,-65535,-65535};
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

TreeNode* pre;
bool flag;
class Solution {
public:
    bool isValidBST(TreeNode* root) {
    	if(!root)
    		return true;
    	flag = 1;
    	bool is = dfsValid(root);
    	
    	return is;
        
    }
    bool dfsValid(TreeNode* root){
    	if(!flag)
    		return flag;
    	if(root->left)
    		dfsValid(root->left);
    	if(pre!=NULL){
    		if(pre->val > root->val){
    			flag = 0;
    			return flag;
			}
		}
		pre = root;
		if(root->right)
			dfsValid(root->right);
		return flag;
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
	void PreOrder(TreeNode* t){
		if(!t)
			return;
		cout<<t->val<<" ";
		PreOrder(t->left);
		PreOrder(t->right);
	}
};


int main(){
	Solution s;
	TreeNode* t;
	t = s.Creat();
	s.PreOrder(t);
	cout<<s.isValidBST(t);
	return 0;
}
