#include <iostream>
#include <vector>
using namespace std;

//construct a tree by using array a and n
int n = 0;
int a[] = { 2, 5, 2, -65535, -65535, 9, -65535, -65535, 0, 7, -65535, 0, 6, -65535, -65535, -65535, -65535 };
typedef struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) :val(x), left(NULL), right(NULL){}
}TreeNode,*Node;

class BinaryTree {
private:
	TreeNode* quene[100];
	int count;
	int head;
	int tail;
public:
	TreeNode* root;

	BinaryTree(){
		Creat(&root);
	}
	vector<int> rightSideView(TreeNode* root) {
		count = 0;
		head = tail = 0;
		vector<int>  retval;
		if (!root)
			return retval;
		quene[tail++] = root;
		count = 1;
		retval.push_back(root->val);
		cout << root->val << endl;;
		flowSearch(retval);
		return retval;
	}
	void flowSearch(vector<int> &vec){

		while (head != tail){
			int i = 0;
			int k = 0;
			while (i<count){
				TreeNode* tmp = quene[head++];

				if (tmp->left != NULL){
					quene[tail] = tmp->left;
					tail++;
					k++;
				}
				if (tmp->right != NULL){
					quene[tail] = tmp->right;
					tail++;
					k++;
				}
				i++;
			}
			count = k;
			TreeNode* p = quene[tail - 1];
			if (count != 0){
				vec.push_back(p->val);
				cout << p->val << " " << endl;
			}
		}
	}
	void Creat(Node* root){
		if (a[n] == -65535){
			*root = NULL;
			n++;
			return;
		}

		*root = new TreeNode(a[n++]);
		//(*root)->val = a[n++];
		Creat(&(*root)->left);
		Creat(&(*root)->right);
	}
	void PreOrder(TreeNode *t){
		if (!t)
			return;
		cout << t->val << " ";
		PreOrder(t->left);
		PreOrder(t->right);
	}
	bool checkBST(TreeNode* root){
		checkBST(root, INT_MAX, INT_MIN);
	}
	bool checkBST(TreeNode* root, int max, int min){
		if (root == NULL)
			return true;
		if ( root->val < min || root->val >= max)
			return false;
		if (!checkBST(root->left, min, root->val) || !checkBST(root->right, root->val, max)){
			return false;
		}
		return true;
	}
};

int main(){
	BinaryTree tree;
	tree.PreOrder(tree.root);

	return 0;
}