#include <iostream>
#include <stack>
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
    bool isPalindrome(ListNode* head) {
    	if(!head || head->next == NULL){
    		return true;
    	}
    	ListNode *pre,*behind;
    	pre = behind = head;
    	stack<int> s;
    	while(pre && pre->next){
    		pre = pre->next->next;
    		s.push(behind->val);
    		behind = behind->next;
    	}
    	if(pre)
    		behind = behind->next;
    		
    	while(behind){
    		if(behind->val != s.top())
    			return false;
    		behind = behind->next;
    		s.pop();		
    	}
    	return true;
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
	int a[] = {1,2,1};
	vector<int> v(a,a+3);
	Solution s;
	ListNode* t = s.creatList(v);
	s.Print(t);
	cout<<"\n"<<s.isPalindrome(t);
	return 0;
} 
