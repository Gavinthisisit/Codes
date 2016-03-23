#include <iostream>
#include <stack>
using namespace std;

int a[] = {12,5,2,-65535,-65535,9,-65535,-65535,18,15,-65535,17,16,-65535,-65535,-65535,19,-65535,-65535};
int n = 0;								//Definition for binary tree
typedef struct TreeNode {
	int val;
    TreeNode *left;
    TreeNode *right;
    //TreeNode(int x) : val(x), left(NULL), right(NULL) {}
}TreeNode,*Node;
  
class BSTIterator {
public:
	stack<TreeNode*> stk;
    BSTIterator(TreeNode *root) {
		if(!stk.empty())
			stk.pop();
		TreeNode *tmp = root;
		while(tmp){
			stk.push(tmp);
			tmp = tmp->left;
		}    	    
    }
    


    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !stk.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tmp;
        tmp = stk.top();
        int retval = tmp->val;
        stk.pop();
        tmp= tmp->right;
        while(tmp){
        	stk.push(tmp);
        	tmp = tmp->left;
        }
        return retval;
    }
};

void PreOrder(TreeNode *t){
   	if(!t)
  		return;
   	PreOrder(t->left);
   	cout<<t->val<<" ";
   	PreOrder(t->right);
}

void CreatBFT(Node *root){
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

int main(){
	Node tree;
	CreatBFT(&tree);
	PreOrder(tree);
	cout<<endl;
	BSTIterator bst = BSTIterator(tree);
	cout<<bst.hasNext()<<endl;
	cout<<bst.next()<<endl;
	
	return 0;
}
