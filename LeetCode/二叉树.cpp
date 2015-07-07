/*ע��ݹ��˼��*/

#include <stdio.h>
#include <malloc.h>


#define MaxChild 10
typedef int ElemType;


/*����������
typedef struct node{
	dataType data;
	struct node *Child[MaxChild];
};*/


/*BiTree t�ȼ���BiTNode *t*/
typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;


/*�ǳ���Ҫ�ĵݹ�˼��*/
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

/*�������*/
void PreOrderTraverse(BiTree T)
{
	/*��Ϊ��ʱ��������*/
	if (T)
	{
		printf("%d ",T->data);

		PreOrderTraverse(T->lchild);

		PreOrderTraverse(T->rchild);
	}
}

/*�������*/
void InOrderTraverse(BiTree T)
{
	if(T)
	{
		InOrderTraverse(T->lchild);

		printf("%c ",T->data);

		InOrderTraverse(T->rchild);
	}
}

/*�������*/
void PosOrderTraverse(BiTree T)
{
	if (T)
	{
		PosOrderTraverse(T->lchild);

		PosOrderTraverse(T->rchild);

		printf("%c ",T->data);
	}
}

/*������*/
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
