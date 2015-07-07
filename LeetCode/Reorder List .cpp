#include <iostream>

using namespace std;



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
struct ListNode{
	int val;
	ListNode *next;
};

/**本办法 ，不能AC 
class Solution {
public:
    void reorderList(ListNode* head) {
    	  deal(head);
		  ListNode* p = head;
		  while(p!=NULL){
		  	cout<<p->val<<"  ";
		  	p = p->next;
		  }  
    }
    void deal(ListNode* head){
    	ListNode* arr[100000];
    	ListNode* p = head;
    	
    	int count = 0;
    	
    	while(p!=NULL){
    		arr[count++] = p;
			p = p->next;	
    	}
    	int i;
    	for(i=0;i<count;i++){
    		ListNode* p;
    		p = arr[i];
    		cout<<p->val<<"  ";
    	}
    	cout<<endl;
    	
    	i = 0;
    	while(i<count/2){
    		ListNode* pre = arr[i];
    		ListNode* post = arr[count-i-1];
    		ListNode* p = post->next;
    		post->next = pre->next;
    		pre->next = post;
			i++;	
    	}
    	p = arr[count/2];
    	p->next = NULL;
    }
    
    ListNode* CreatList(int a[],int n){
    	int i;
    	ListNode* head = new ListNode;    	
    	head->val = a[0];
    	head->next = NULL;
    	ListNode* p;
    	p = head;
    	
    	for(i=1;i<n;i++){
    		ListNode* tmp = new ListNode;
    		tmp->val = a[i];
    		tmp->next = NULL;
    		p->next = tmp;
  			p = p->next;
    	}
    	return head;
    }
};

int main(){
	int a[] = {2,1,3};
	Solution s;
	
	ListNode* h = s.CreatList(a,3);
//	s.deal(h);
	s.reorderList(h);
	
	return 0;
}

**/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


class Solution {
public:
    void reorderList(ListNode* head) {
    	if(head == NULL)
    		return;
    	ListNode* fast = head;
    	ListNode* slow = head;
    	ListNode* tmp;
    	if(head!= NULL && head->next!=NULL){
    		while(fast!=NULL && fast->next!=NULL){
    			slow = slow->next;
    			fast = fast->next->next;
    			
    			tmp = slow->next;	
    		}
    		
    		ListNode* p = head;
    		slow->next = NULL;

    		tmp = reverseList(tmp);
    		
    		while(p!=NULL && tmp!=NULL){
    			ListNode* m = p->next;
    			p->next = tmp;
    			tmp = tmp->next;
    			p = p->next;
    			p->next = m;
    			p = p->next;	
    		}
    		
    		
    	}
    	ListNode* p = head;
    	 while(p!=NULL){
		  	cout<<p->val<<"  ";
		  	p = p->next;
		  }
		  cout<<endl;
		    
    }
    ListNode* CreatList(int a[],int n){
    	int i;
    	ListNode* head = new ListNode;    	
    	head->val = a[0];
    	head->next = NULL;
    	ListNode* p;
    	p = head;
    	
    	for(i=1;i<n;i++){
    		ListNode* tmp = new ListNode;
    		tmp->val = a[i];
    		tmp->next = NULL;
    		p->next = tmp;
  			p = p->next;
    	}
    	return head;
    }
    ListNode* reverseList(ListNode* head){
    	if(head==NULL)
    		return head;
		ListNode* p;
		p = head->next;
		head->next = NULL;
		
		while(p!=NULL){
			ListNode* tmp = p;
			p = p->next;
			tmp ->next = head;
			head = tmp;
		}
		return head;   	
    }
};


int main(){
	int a[] = {1,2,3,4,5,6,7,8,9,10};
	Solution s;
	
	ListNode* h = s.CreatList(a,10);
//	s.deal(h);
	s.reorderList(h);
	return 0;
} 
