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
    vector<vector<int> > zigzagLevelOrder(TreeNode* root) {
    	vector<vector<int> > retval;
		if(root == NULL)
			return retval;
		LevelOrder(root,retval);
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
	void LevelOrder(TreeNode* root,vector<vector<int> >& retval){
		if(root == NULL)
			return;
		TreeNode* quene[10000];
		vector<int> tmp;
		vector<int> ret;
		int head =  0;
		int tail = 0;
		quene[tail++] = root;
		
		bool flag  =0;
		int count = 1;
		while(head != tail){
			int t_count = 0;
			tmp.clear();
			while(count){
				TreeNode* p = quene[head++];
				tmp.push_back(p->val);
					if(p->left != NULL){
						quene[tail++] = p->left;
						t_count++;
					}
					if(p->right != NULL){
						quene[tail++] = p->right;
						t_count++;
					}
				count--;
			}
			ret.clear();
			if(flag){
				for(int i=tmp.size()-1;i>=0;i--)
					ret.push_back(tmp[i]);
				retval.push_back(ret);
				flag = 0;
			}
			else{
				retval.push_back(tmp);
				flag = 1;
			}
			
			count = t_count;
		}
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
	vector<vector<int> > ret;
	ret = s.zigzagLevelOrder(root);
	for(int i=0;i<ret.size();i++){
		for(int j=0;j<ret[i].size();j++)
			cout<<ret[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
