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
	
/**	
    ListNode* deleteDuplicates(ListNode* head) {
    	if(!head)
			return head;
		ListNode* p = head->next;
		ListNode* pre = head;
		int curVal = head->val;
		while(p && p->val == curVal){
			p = p->next;
			if(p->val != curVal){
				curVal = p->val;
				pre = p;
				p = p->next;
				
			}
		}
		head = pre;
		p = head->next->next;
		curVal = head->next->val;
		while(p->next){
			while(p && p->val == curVal){
				p = p->next;
			}
			if(p && p->next && p->next->val!=p->val){
				pre->next = p;
				pre = p;
				p = p->next;
				curVal = p->val;
			}
			else if(p && p->next){
				curVal = p->val;
			}
			else if(!p->next){
				pre->next = p;
				return head;
			}
			else
				return head;	
				
		}
    }
**/
	ListNode* deleteDuplicates(ListNode* head) {
		if(!head || head->next ==NULL){
			return head;
		}
		ListNode* p = new ListNode(-1);   //好巧妙的添加头结点 
		p->next = head;
		ListNode *pre,*cur;
		pre = p;
		cur = head;
		while(cur){
			bool flag = 0;
			while(cur->next && cur->next->val == cur->val){
				flag = 1;
				cur= cur->next;
			}
			if(flag){
				cur = cur->next;
				continue;
			}
			pre->next = cur;
			pre = pre->next;
			cur = cur->next;
		}
		pre->next = cur;    //链表尾节点
		return p->next;  
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
