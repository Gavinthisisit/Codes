#include <iostream>

using namespace std;


//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
};
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
    	if(!head || !head->next)
    		return head;
        ListNode *before,*behind;
		int i = 0;
		before = head;
		behind = head;
		ListNode* p = head;
		int count = 0;
		while(p){
			count++;
			p = p->next;
		}
		if(k>=count)
			count = k%count;
		else
			count = k;
		if(count==0)
			return head;
		int flag = 0;
		while(before->next){
			before = before->next;
			if(i>=count)
				behind = behind->next;
			i++;	
		}
		ListNode* tmp = head;
		
		head = behind->next;
		behind->next = NULL;
		before->next = tmp;
		return head;       
    }
    void creatList(int a[],int n,ListNode* head){
    	int i = 0;
    	head->val = a[i++];
    	head->next = NULL;
    	ListNode* p = head;
    	while(i<n){
    		ListNode* tmp = new ListNode;
    		tmp->val = a[i++];
    		tmp->next = NULL;
    		p->next = tmp;
    		p = p->next;
    	}
    }
};

int main(){
	int a[] = {1,2,3};
	Solution s;
	ListNode* head = new ListNode;
	s.creatList(a,3,head);
	ListNode* p = head;
	
	while(p){
		cout<<p->val<<" ";
		p = p->next;
	}
	cout<<endl;
	p = s.rotateRight(head,10);
	
	while(p){
		cout<<p->val<<" ";
		p = p->next;
	}
	cout<<endl;
	
	return 0;
}
