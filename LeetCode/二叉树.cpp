/*注意递归的思想*/

#include <stdio.h>
#include <malloc.h>


#define MaxChild 10
typedef int ElemType;


/*多重链表结点
typedef struct node{
	dataType data;
	struct node *Child[MaxChild];
};*/


/*BiTree t等价于BiTNode *t*/
typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;


/*非常重要的递归思想*/
void CreatBiTree(BiTree *T)
{
	ElemType c;

	scanf("%d",&c);
	if (c==-1)
	{
		*T = NULL;
		return;
	}
	else
	{
		*T = (BiTNode *)malloc(sizeof(BiTNode));
		(*T)->data = c;
		CreatBiTree(&((*T)->lchild));
		CreatBiTree(&((*T)->rchild));
	}
	
}

/*先序遍历*/
void PreOrderTraverse(BiTree T)
{
	/*树为空时结束遍历*/
	if (T)
	{
		printf("%d ",T->data);

		PreOrderTraverse(T->lchild);

		PreOrderTraverse(T->rchild);
	}
}

/*中序遍历*/
void InOrderTraverse(BiTree T)
{
	if(T)
	{
		InOrderTraverse(T->lchild);

		printf("%c ",T->data);

		InOrderTraverse(T->rchild);
	}
}

/*后序遍历*/
void PosOrderTraverse(BiTree T)
{
	if (T)
	{
		PosOrderTraverse(T->lchild);

		PosOrderTraverse(T->rchild);

		printf("%c ",T->data);
	}
}

/*销毁树*/
void DestroyTree(BiTree T)
{
	if (T)
	{
		DestroyTree(T->lchild);

		DestroyTree(T->rchild);

		free(T);
	}
}


void main()
{
	BiTree tree;

	CreatBiTree(&tree);

	PreOrderTraverse(tree);

	printf("\n");
	
	InOrderTraverse(tree);

	printf("\n");

	PosOrderTraverse(tree);

	printf("\n");

	DestroyTree(tree);
}
