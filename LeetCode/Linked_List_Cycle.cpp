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
    bool hasCycle(ListNode *head) {
    	if(!head)
			return false;
    	ListNode *pre,*p;
    	pre = head;
    	p = head;
    	while(pre && pre->next){
    		if(pre==p || pre->next == p)
    			return true;
			pre = pre->next->next;
    		p = p->next;	
    	}
		return  false;
    }
	ListNode *detectCycle(ListNode *head) {
    	if(!head)
			return false;
    	ListNode *pre,*p;
    	pre = head;
    	p = head;
    	while(pre && pre->next){
			if(pre)
				pre = pre->next;
			if(pre)
				pre = pre->next;
    		if(p)
				p = p->next;
    		if(pre==p){
    			ListNode* ret = head;
				while(ret!=p){
					ret = ret->next;
					p = p->next;
				}
				return ret;		
    		}
    		
    	}
		return  NULL;	    
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
//    	ret->next = retval;
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
	int a[] = {1};
	int b[] = {2,4,6,8,10};
	vector<int> v1(a,a+1);
	vector<int> v2(b,b+5);
	Solution s;
	ListNode* t1 = s.creatList(v1);
//	s.Print(t1);
//	ListNode* t2 = s.creatList(v2); 
//	s.Print(t2);
	cout<<s.hasCycle(t1);
//	s.Print(p);
	return 0;
} 
