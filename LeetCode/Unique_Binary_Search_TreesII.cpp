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

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return creatTree(1,n);
    }
    vector<TreeNode*> creatTree(int start,int end){
    	vector<TreeNode*> result;
    	if(start > end){
    		result.push_back(NULL);
    		return result;
    	}
    	for(int i=start;i<=end;i++){
    		vector<TreeNode*> left = creatTree(start,i-1);
    		vector<TreeNode*> right = creatTree(i+1,end);
    		for(int j=0;j<left.size();j++){
    			for(int k=0;k<right.size();k++){
    				TreeNode* root = new TreeNode(i);
    				root->left = left[j];
    				root->right = right[k];
    				result.push_back(root);
    			}
    		}
    	}
    	return result;	
    }
};


int msin(){
	vector<TreeNode*> vec;
	Solution s;
	vec = s.generateTrees(5);
	cout<<vec.size();
	return 0;
}
