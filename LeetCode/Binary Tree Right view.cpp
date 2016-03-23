#include <iostream>
#include <vector>

using namespace std;

int a[] = {2,5,2,-65535,-65535,9,-65535,-65535,0,7,-65535,0,6,-65535,-65535,-65535,-65535};
//int a[] = {1,2,-65535,-65535,3,-65535,-65535};
int n = 0;

	//Definition for a binary tree node.
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
}TreeNode,*Node;



class Solution {
private:
	TreeNode* quene[100];
	int count;
	int head;
	int tail;
public:
    vector<int> rightSideView(TreeNode* root) {
        count = 0;
        head = tail = 0;
        vector<int>  retval;
        if(!root)
        	return retval;
        quene[tail++] = root;
        count = 1;
		retval.push_back(root->val);
		cout<<root->val<<endl;;
        flowSearch(retval);
		return retval;
    }
    void flowSearch(vector<int> &vec){

    	while(head != tail){
    		int i = 0;
    		int k = 0;
    		while(i<count){
    			TreeNode* tmp = quene[head++];

    			if(tmp->left != NULL){
    				quene[tail] = tmp->left;
    				tail++;
    				k++;
    			}
    			if(tmp->right != NULL){
    				quene[tail] = tmp->right;
    				tail++;
    				k++;
    			}
				i++;
    		}
    		count = k;
    		TreeNode* p = quene[tail-1];
			if(count!=0){
    			vec.push_back(p->val);
				cout<<p->val<<" "<<endl;
			}
    	}
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
		cout<<t->val<<" ";
	   	PreOrder(t->left);
	   	PreOrder(t->right);
	}
};


int main(){
	Solution s;
	TreeNode* t;
	s.Creat(&t);
	s.PreOrder(t);
	cout<<endl;
	vector<int> v;
	v = s.rightSideView(t);
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<" ";
	cout<<endl;
	return 0;
}
