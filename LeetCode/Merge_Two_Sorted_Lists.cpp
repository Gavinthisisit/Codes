#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 **/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    	ListNode *up,*down;
    	up = l1;
    	down = l2;
    	ListNode* head = new ListNode(-1);
    	ListNode* p = head;
    	while(up && down){
    		if(up->val < down->val){
    			ListNode* tmp = up;
    			up = up->next;
    			tmp->next = p->next;
    			p->next = tmp;
    			p = p->next;
    		}
    		else{
    			ListNode* tmp = down;
    			down = down->next;
    			tmp->next = p->next;
    			p->next = tmp;
    			p = p->next;
    		}
    	}
    	if(up){
    		p->next = up;
    	}
    	if(down)
    		p->next = down;
    	return head->next;    
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
    void Print(ListNode* p){
		ListNode* t = p;
    	while(t!=NULL){
    		cout<<t->val<<" ";
    		t = t->next;
    	}
    	
    	cout<<endl;
    }
};

int main(){
	int a[] = {1,3,5,7,9,11,13,15};
	int b[] = {2,4,6,8,10};
	vector<int> v1(a,a+8);
	vector<int> v2(b,b+5);
	Solution s;
	ListNode* t1 = s.creatList(v1);
	s.Print(t1);
	ListNode* t2 = s.creatList(v2); 
	s.Print(t2);
	ListNode* p = s.mergeTwoLists(t1,t2);
	s.Print(p);
	return 0;
} 
