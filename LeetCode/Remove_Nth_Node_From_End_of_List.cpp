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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
    	if(!head || n<0)
			return head;
		int i = 0;
		ListNode* pre = head;
		ListNode* after = head;
		while(pre){
			if(i>n){
				after = after->next;
			}
			pre = pre->next;
			i++;
		}
		if(i==n)
			return head->next;
		else if(i>=n){
			after->next = after->next->next;
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
	int a[] = {1,2,3,4,5,6,7};
	vector<int> v(a,a+7);
	Solution s;
	ListNode* r = s.creatList(v);
	s.Print(r);
	cout<<endl;
	ListNode* t = s.removeNthFromEnd(r,8);
	s.Print(t);
	return 0;
}
