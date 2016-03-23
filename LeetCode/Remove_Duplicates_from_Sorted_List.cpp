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
    ListNode* deleteDuplicates(ListNode* head) {
    	if(!head)
			return head;
		int curval = head->val;
		ListNode* pre = head;
		ListNode* p = head->next;
		while(p){
			if(p->val==curval){
				pre->next = p->next;
				p = p->next;
			}
			else{
				curval = p->val;
				pre = pre->next;
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
	int a[] = {1,2,3,3,4,5,5};
	vector<int> v(a,a+7);
	Solution s;
	ListNode* r = s.creatList(v);
	s.Print(r);
	cout<<endl;
	ListNode* t = s.deleteDuplicates(r);
	s.Print(t);
	return 0;
}
