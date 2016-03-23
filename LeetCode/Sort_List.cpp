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
    ListNode* swapPairs(ListNode* head) {
    	if(head==NULL)
			return head;
		ListNode* p = head;
		ListNode* tail = NULL;
		while(tail!=head->next){
			p = head;
			while(p!=tail){
				ListNode* tmp = p->next;
				if(p->val > tmp->val){
					int t = p->val;
					p->val = tmp->val;
					tmp->val = t;
				}
				p = p->next;
				if(p->next==tail)
					tail = p; 
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
    void Print(ListNode* t){
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
	ListNode* t = s.creatList(v);
	s.Print(t);
	cout<<endl;
	ListNode* p = s.swapPairs(t);
	s.Print(p);
	return 0;
} 
