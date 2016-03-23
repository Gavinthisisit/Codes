#include <iostream>
#include <vector>
#include <string>

using namespace std;

int a[] = {2,5,2,-65535,-65535,9,-65535,-65535,0,7,-65535,0,6,-65535,-65535,-65535,3,-65535,-65535};
//int a[] = {1,2,-65535,-65535,3,-65535,-65535};
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
		return trans(sum_path);
    }
    void dfs(TreeNode *tree,vector<int> &path){
    	if(tree->left == NULL && tree->right == NULL){
    		sum_path.push_back(path);
    		return;
    		
    	}
    	if(tree->left){
			Node tmp = tree->left;
    		path.push_back(tmp->val);
    		dfs(tmp,path);
    		path.pop_back();
    	}
    	if(tree->right){
			Node tmp = tree->right;
    		path.push_back(tmp->val );
    		dfs(tmp,path);
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
				cout<<vec[i][j];
				num = num*10+ vec[i][j];
				j++;
			}
			cout<<endl;
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
	    Creat(&((*root)->left));
		Creat(&((*root)->right)); 
	}
	void PreOrder(TreeNode *t){
	   	if(!t)
	  		return;
	   	PreOrder(t->left);
	   	cout<<t->val<<" ";
	   	PreOrder(t->right);
	}
};



int main(){
	Node tree;
	Solution s;
	s.Creat(&tree);
	s.PreOrder(tree);
	cout<<endl;
	cout<<s.sumNumbers(tree)<<endl;
	cout<<endl;
	return 0;
}
