#include <iostream>
#include <string>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
};
 
class Solution {
public:
	ListNode *CreatList(int a[],int n){
		int i = 0;
		ListNode *list = new ListNode;
		list->val = a[i++];
		list->next = NULL;
		
		ListNode *p = list;
		while(i<n){
			ListNode *tmp = new ListNode;
			tmp->val = a[i++];
			tmp->next = NULL;
			p->next = tmp;
			p = p->next;	
		}
		return list;
	} 
    ListNode *swapPairs(ListNode *head) {
		if(!head)
			return head;
    	ListNode *front,*behind;
    	ListNode *retval;
    	front = head;
		ListNode *tmp,*Cur_tail;
    	if(!head->next)
    		return head;
    	else
    		behind = front->next;
    	retval = behind;
    	tmp = behind->next;
    	behind->next = front;
    	front->next = NULL;
    	Cur_tail = front;
    	while(tmp && tmp->next){
    		front = tmp;
    		behind = tmp->next;
    		tmp = behind->next;
    		Cur_tail->next = behind;
    		behind->next = front;
			front->next = NULL;
			Cur_tail = front;	
    	}
		Cur_tail->next = tmp;
		return retval;
    }
    void printList(ListNode *list){
    	ListNode *tmp;
    	tmp = list;
    	while(tmp->next!=NULL){
    		cout<<tmp->val<<"->";
    		tmp = tmp->next;
    	}
		cout<<tmp->val<<endl;; 	
    }
    void destroyList(ListNode *list){
    	ListNode *tmp = list;
    	ListNode *del;
    	while(!tmp){
    		del = tmp;
    		tmp = tmp->next;
    		delete del;
    	}
    }
};




int main(){
	
	int a[5] = {1,2,3,4,5};
	Solution s;
	ListNode *list;
	list = s.CreatList(a,5);
//	s.printList(list);
	list = s.swapPairs(list);
	s.printList(list);
//	s.destroyList(list);
	return 0;
}
