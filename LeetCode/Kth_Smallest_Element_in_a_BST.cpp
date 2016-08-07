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
	int kthSmallest(TreeNode* root, int k) {

	}
	TreeNode* BuildTree(vector<int>& vec,int pos){
		if (vec[pos] == -65535)
			return NULL;
		TreeNode* root = new TreeNode(vec[pos]);

		root->left  = BuildTree(vec, ++pos);
		root->right = BuildTree(vec, ++pos);
		
		return root;
	}
	void PrintTree(TreeNode* root){
		if (!root)
			return;
		cout << root->val<<" ";
		PrintTree(root->left);
		PrintTree(root->right);
	}
	void DestroyTree(TreeNode* root){
		if (!root)
			return;
		TreeNode* left  = root->left;
		TreeNode* right = root->right;
		delete root;
		DestroyTree(left);
		DestroyTree(right);
	}
};

int main(){
	return 0;
}