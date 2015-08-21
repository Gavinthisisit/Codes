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
    ListNode* removeElements(ListNode* head, int val) {
    	if(!head)   
			return head;	
		while(head && head->val==val){
			head = head->next;
		}
		if(!head)
			return head;
		ListNode* p = head->next;
		ListNode* pre = head;
		while(p){
			if(p->val == val){
				pre->next = p->next;
				p = pre->next;
			}
			else{
				pre = p;
				p = p->next;
			}	
		}
		return head;		 
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
    }
};
int main(){
	int a[] = {1};
	vector<int> v(a,a+1);
	Solution s;
	ListNode* r = s.creatList(v);
	s.Print(r);
	cout<<endl;
	ListNode* t = s.removeElements(r,1);
	s.Print(t);
	return 0;
}
