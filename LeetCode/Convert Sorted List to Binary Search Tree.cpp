#include <iostream>


using namespace std;


/**
 * Definition for singly-linked list.
 **/
struct ListNode {
    int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
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
    
/**
    TreeNode *sortedListToBST(ListNode *head)
	{
	    int len = 0;
        ListNode * node = head;
        while (node != NULL)
        {
            node = node->next;
            len++;
        }
        return buildTree(head, 0, len-1);
    }
    
    TreeNode *buildTree(ListNode *&node, int start, int end)
    {
        if (start > end) return NULL;
        int mid = start + (end - start)/2;
        TreeNode *left = buildTree(node, start, mid-1);
        TreeNode *root = new TreeNode(node->val);
        root->left = left;
        node = node->next;
        root->right = buildTree(node, mid+1, end);
        return root;
    }
    ListNode* CreatList(int a[],int n){
    	int i = 0;
    	ListNode *head = new ListNode(a[i++]);
    	ListNode* p = head;
    	while(i<n){
    		ListNode* tmp = new ListNode(a[i++]);
    		p->next = tmp;
    		p = p->next;
    	}
    	return head;
    }
    
    ListNode* findList_mid(ListNode* list){
    	if(!list)
    		return NULL;
    	ListNode* mid;
		ListNode* tail;
		ListNode* pre = NULL;
    	mid = tail = list;
    	while(tail->next!=NULL && tail!=NULL){
			pre = mid;
    		mid = mid->next;
    		tail = tail->next->next;
    	}
		if(pre)
			pre->next = NULL;
    	return mid;
    }
	void PreOrder(TreeNode* t){
		if(!t)
			return ;
		cout<<t->val<<" ";
		PreOrder(t->left);
		PreOrder(t->right);
	}
**/
    TreeNode *sortedListToBST(ListNode *head)
	{
	    int len = 0;
        ListNode * node = head;
        while (node != NULL)
        {
            node = node->next;
            len++;
        }
        return buildTree(head, 0, len-1);
    }
    
    TreeNode *buildTree(ListNode *&node, int start, int end)
    {
        if (start > end) return NULL;
        int mid = start + (end - start)/2;
        TreeNode *left = buildTree(node, start, mid-1);
        TreeNode *root = new TreeNode(node->val);
        root->left = left;
        node = node->next;
        root->right = buildTree(node, mid+1, end);
        return root;
    }
};

int main(){
	int a[] = {1,2,3,4,5,6,7};
	Solution s;
	ListNode* list = s.CreatList(a,7);
	ListNode* p = list;
	while(p){
		cout<<p->val<<" ";
		p = p->next;
	}
	cout<<endl;
	TreeNode* root;
	root = s.sortedListToBST(list);
	s.PreOrder(root);
	cout<<endl;
	return 0;
}
