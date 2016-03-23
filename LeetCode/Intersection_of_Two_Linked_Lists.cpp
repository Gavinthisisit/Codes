#include <iostream>
#include <vector>

using  namespace std;

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    	if(!headA || !headB)
			return NULL;
		ListNode* a = headA;
		ListNode* b = headB;
		int la,lb;
		la = lb = 0;
		while(a->next){
			a = a->next;
			la++;
		}
		while(b->next){
			b = b->next;
			lb++;
		}
		if(a!=b)
			return NULL;
		int dif = la>lb?(la-lb):(lb-la);
		a = headA;
		b = headB;
		while(dif){
			if(la>lb)
				a = a->next;
			else
				b = b->next;
			dif--;
		}
		while(a!=b){
			a = a->next;
			b = b->next;
		}
		return a;
				    
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    	if(!l1 && !l2)
			return NULL;
		if(!l1)
			return l2;
		if(!l2) 
			return l1;
		ListNode *p1,*p2;
		p1 = l1;
		p2 = l2;
		int flag = 0;
		ListNode* pre2;
		ListNode* pre1;
		while(p1 && p2){
			int tmp = p1->val+p2->val+flag;
			if(tmp>=10){
				flag = 1;
				tmp -= 10;
			}
			else
				flag = 0;
			p1->val = tmp;
			pre2 = p2;
			pre1 = p1;
			p1 = p1->next;
			p2 = p2->next;
			pre2->next = NULL;
		}
		int first =1;
		while(flag){
			int count = 0;
			if(p1){
				count = p1->val + 1;
				if(count>=10){
					flag = 1;
					count -= 10;
				}
				else
					flag = 0;
				p1->val = count;
				pre1 = p1;
				p1 = p1->next;
			}	
			else if(p2){
				count = p2->val + 1;
				if(count>=10){
					flag = 1;
					count -= 10;
				}
				else
					flag = 0;
				p2->val = count;
				if(first){
					pre1->next = p2;
					first = 0;
				}
				else
					pre1 = p2;
				p2 = p2->next;
			}
			else{
				ListNode* tmp = new ListNode(1);
				pre1->next = tmp;
				flag = 0;
			}
		}
		return l1;   
    }
};

int main(){
	int a[] = {1};
	int b[] = {9,9};
	vector<int> v1(a,a+1);
	vector<int> v2(b,b+2);
	Solution s;
	ListNode* t1 = s.creatList(v1);
	ListNode* t2 = s.creatList(v2);
//	t2->next->next = t1->next->next->next->next;
	s.Print(t1);
	s.Print(t2);
	ListNode* p = s.addTwoNumbers(t2,t1);
	s.Print(p);
	return 0;
} 
