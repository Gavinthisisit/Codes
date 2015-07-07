#include <iostream>
#include <vector>
#include <string>

using namespace std;

int a[] = {12,5,2,-65535,-65535,9,-65535,-65535,18,15,-65535,17,16,-65535,-65535,-65535,19,-65535,-65535};
int n = 0;	
//Definition for binary tree
typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
}TreeNode,*Node;

class Solution {
private:
	vector<vector<int> > sum_path;
public:
    int sumNumbers(TreeNode *root) {
    	sum_path.clear();
    	if(!root)
    		return 0;
    	vector<int> path;
    	path.push_back(root->val);
		dfs(root,path);    
    }
    void dfs(TreeNode *tree,vector<int> &path){
    	if(tree->left == NULL && tree->right == NULL){
    		sum_path.push_back(path);
    		return;
    		
    	}
    	if(tree->left){
    		path.push_back((tree->left)->val);
    		dfs(tree->left,path);
    		path.pop_back();
    	}
    	if(tree->right){
    		path.push_back( (tree->right)->val );
    		dfs(tree->right,path);
    		path.pop_back();
    	}	
    }
    int trans(vector<vector<int> > vec){
    	int i,j;
    	int retval = 0;
    	
    	for(i=0;i<vec.size();i++){
    		j = 0;
    		int num = 0;
			while(j<vec[i].size()){
				num = num*10+ vec[i][j];
				j++;
			}
			retval += num;
    	}
    	return retval;
    }
    void Creat(Node *root){
	    if(a[n] == -65535){
	    	*root = NULL;
	    	n++;
	    	return;
	    }
	   		
	    *root = new TreeNode;
	   	(*root)->val = a[n++];
	    CreatBFT(&((*root)->left));
		CreatBFT(&((*root)->right)); 
	}
};



int main(){
	Node tree;
	Solution s;
	s.Creat(&tree);
	s.maxPathSum(tree);
	PreOrder(tree);
	cout<<endl;
	return 0;
}
