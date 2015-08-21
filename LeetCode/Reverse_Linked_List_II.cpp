#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
    	if(m>=n)
			return head;
		int i=0;
		ListNode* p = head;
		ListNode *pre,*start,*end,*behind;
		int flag = 0;
		
		if(m<=1){
			pre = NULL;
			start = p;
		}
		while(i<n && p->next){
			if(i==m-2){
				pre = p;
				start = p->next;
			}
			else if(i==n-1){
				end = p;
				behind = p->next;
				flag = 1;
				break;
			}
			p = p->next;
			i++;	
		}
		if(!p->next && !flag){
			end = p;
			behind = NULL;
		}
		end->next = NULL;
		ListNode* re = reverseList(start);
		if(pre)
			pre->next = re;
		else
			head = re;
			
		if(behind){
			ListNode* t = re;
			while(re->next){
				re = re->next;
			}
			re->next = behind;
		}
		return head;
    }
    ListNode* reverseList(ListNode* head) {
    	if(!head || !head->next)
    		return head;

		ListNode* p = head->next;
    	ListNode* pre = head;
    	pre->next = NULL;
    	ListNode* old = NULL;
		while(p->next!=NULL){
			old = p->next;
			p->next = pre;
			pre = p;
			p = old;	
		}
		p->next = pre;
		return p;  
    }
    ListNode* creatList(vector<int>& v){
    	if(v.size()==0)
    		return NULL;
    	ListNode* retval = new ListNode(v[0]);
    	ListNode* ret = retval;
    	int i = 1;
    	
    	while(i<v.size()){
    		ListNode* tmp = new ListNode(v[i]);
    		ret->next = tmp;
    		ret = ret->next; 
    		i++;
    	}
    	return retval;
    }
    void Print(ListNode* t){
    	while(t!=NULL){
    		cout<<t->val<<" ";
    		t = t->next;
    	}
    }
};


int main(){
	int a[] = {3,5};
	vector<int> v(a,a+2);
	Solution s;
	ListNode* t = s.creatList(v);
	ListNode* p = s.reverseBetween(t,1,2);
	s.Print(p);
	return 0;
} 
