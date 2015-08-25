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
    ListNode* insertionSortList(ListNode* head) {
    	if(!head)
			return NULL;
		ListNode* retval = head;
		ListNode* p = head->next;
		retval->next = NULL;
		while(p){
			ListNode* pos = findPos(retval,p->val);
			ListNode* tmp = p;
			p = p->next;
			if(!pos){
				tmp->next = retval;
				retval = tmp;
			}
			else{
				tmp->next = pos->next;
				pos->next = tmp;	
			}		 
		} 
		return retval;   
    }
    ListNode* findPos(ListNode* l,int t){
    	if(l->val > t)
    		return NULL;
    	ListNode* p = l;
    	while(p->next){
			if(p->val<=t && p->next->val>t)
				return p;
			p = p->next; 
		}
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
	int a[] = {7,6,5,4,3,4,1};
	vector<int> v(a,a+7);
	Solution s;
	ListNode* t = s.creatList(v);
	s.Print(t);
	ListNode* p = s.insertionSortList(t);
	s.Print(p);
	return 0;
} 
