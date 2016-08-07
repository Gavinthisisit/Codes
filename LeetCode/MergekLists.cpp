#include <iostream>
#include <vector>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



class Solution {
public:
	ListNode* creatList(int a[],int n){
		ListNode* head = new ListNode(a[0]);
		ListNode* tmp = head;
		int i = 1;
		while (i < n){
			ListNode* p = new ListNode(a[i]);
			tmp->next = p;
			tmp = p;
			++i;
		}
		return head;
		
	}
	ListNode* mergeKLists(vector<ListNode*>& lists){
		int n = lists.size();
		if (!n)
			return NULL;
		if (n == 1)
			return lists[0];
		return mergeKLists2(lists, 0, n - 1);
	}
	ListNode* mergeKLists2(vector<ListNode*>& lists,int start,int end) {
		if (start > end)
			return NULL;
		if (start == end)
			return lists[start];
		int mid = (start+end) / 2;
		ListNode*  l1 = mergeKLists2(lists, start, mid);
		ListNode* l2 = mergeKLists2(lists, mid + 1, end);
		return merge2List(l1, l2);
	}
	ListNode* merge2List(ListNode* l1, ListNode* l2){
		ListNode* head = NULL;
		if (!l1)
			return l2;
		if (!l2)
			return l1;
		int x1 = l1->val;
		int x2 = l2->val;
		if (x1 <= x2){
			head = l1;
			l1 = l1->next;
			head->next = NULL;
		}
		else{
			head = l2;
			l2 = l2->next;
			head->next = NULL;
		}
		
		ListNode* tmp = head;
		int min = INT_MAX;
		while (l1 != NULL && l2 != NULL){
			if (l1->val <= l2->val){
				tmp->next = l1;
				l1 = l1->next;
				tmp = tmp->next;
				tmp->next = NULL;
			}
			else{
				tmp->next = l2;
				l2 = l2->next;
				tmp = tmp->next;
				tmp->next = NULL;
			}
		}
		if (l1)
			tmp->next = l1;
		if (l2)
			tmp->next = l2;
		return head;
	}
	void PrintList(ListNode* l){
		ListNode* tmp;
		while (l){
			cout << l->val << " ";
			tmp = l;
			l = l->next;
			delete tmp;
		}
	}
};


int main(){
	int a[] = { 1, 3, 5, 7, 9 };
	int b[] = {2, 4, 6, 8, 10};
	int c[] = {0,11,13,15,17};
	int d[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	Solution s;
	ListNode* a1 = NULL;//; s.creatList(a, 5);
	ListNode* a2 = NULL;// s.creatList(b, 5);
	ListNode* a3 = s.creatList(c, 5);
	ListNode* a4 = s.creatList(d, 9);
	vector<ListNode*> vec;
	vec.push_back(a1);
	vec.push_back(a2);
//	vec.push_back(a3);
//	vec.push_back(a4);
	ListNode* retval = s.mergeKLists(vec);
	s.PrintList(retval);
	return 0;
}