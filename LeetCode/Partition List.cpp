#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.*/
struct ListNode {
	int val;
	ListNode *next;
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
    	ListNode *less_t,*large_t;
    	ListNode *less_h,*large_h;
    	less_t = large_t = NULL;
    	less_h = large_h = NULL;
    	ListNode *point = head;
    	int Nodedata;
    	if(!head)
    		return less_h;
    	while(point!=NULL){
    		Nodedata = point->val;
			if(Nodedata < x){
				if(less_h == NULL){
					less_h = point;
					less_t = point;	
				}
				else{
					less_t->next = point;
					less_t = less_t->next;
				}
				point = point->next;
				less_t->next = NULL;			
			}
			else{
				if(large_h == NULL){
					large_h = point;
					large_t = point;
				}
				else{
					large_t->next = point;
					large_t= large_t->next;
				}
				point = point->next;
				large_t->next = NULL;
			}
    	}
    	if(less_t){
    		less_t->next = large_h;
    		return less_h;
    	}else
    		return large_h;
    }
    
};

ListNode* CreatList(int a[],int n){
	int i = 1;
	ListNode *head = new ListNode;
	head->val = a[0];
	head->next = NULL;
	ListNode *p = head;
	while(i<n){
		ListNode *tmp = new ListNode;
		tmp->val = a[i++];
		tmp->next = NULL;
		p->next = tmp;
		p = p->next; 
	}
	return head;
}

int main(){
	int a[] = {1,1};
	ListNode *list = NULL;
	list = CreatList(a,2);
/*	ListNode *p = list;
	while(p->next != NULL){
		cout<<p->val<<",";
		p = p->next;
	}
	cout<<p->val<<endl;*/
	Solution s;
	
	ListNode *p;
	
	p = s.partition(list,2);
	while(p->next != NULL){
		cout<<p->val<<",";
		p = p->next;
	}
	cout<<p->val<<endl;
	return 0;
}
