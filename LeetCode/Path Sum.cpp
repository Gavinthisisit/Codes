#include <iostream>
#include <malloc.h>
using namespace std;

typedef int ElemType;

typedef struct TreeNode{
	ElemType val;
	struct TreeNode *lchild,*rchild;
}BiTNode,*BiTree;


	void CreatBiTree(BiTree *T){
		ElemType c;
		cin>>c;
		if(c == '@')
			T = NULL;
		else{
			*T = (BiTNode *)malloc(sizeof(BiTNode));
			(*T)->val = c;
			CreatBiTree(&((*T)->lchild));
			CreatBiTree(&((*T)->rchild));
		}
	}
	
		/*先序遍历*/
	void PreOrderTravers(BiTree T){
		if(T){
			cout<<T->val<<" ";
			PreOrderTravers(T->lchild);
			PreOrderTravers(T->rchild);
		}
	}
/*
class Solution {
public:
	void CreatBiTree(BiTree *T){
		ElemType c;
		cin>>c;
		if(c == '@')
			T = NULL;
		else{
			*T = (BiTNode *)malloc(sizeof(BiTNode));
			(*T)->data = c;
			CreatBiTree(&((*T)->lchild));
			CreatBiTree(&((*T)->rchild));
		}
	}
	
	//先序遍历
	void PreOrderTravers(BiTree t){
		if(T){
			cout<<T->data<<" ";
			PreOrderTravers(T->lchild);
			PreOrderTravers(T->rchild);
		}
	}
    bool hasPathSum(TreeNode *root, int sum) {
        
    }
};
*/
int main(){
	BiTree Bi;
	CreatBiTree(&Bi);
	PreOrderTravers(Bi);
	return 0;
}
