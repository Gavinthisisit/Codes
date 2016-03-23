#include <iostream>
#include <vector>
#include <limits.h>

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
	/*
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    	int n = lists.size();
    	if(n == 0)
			return NULL;
//		if(!lists[0] && !lists[1])
//		    return NULL;
		if(n == 1)
			return lists[0];
		int count = n;
		ListNode* p = new ListNode(-1);
		ListNode* t = p;
		while(count>=2){
			count = 0;
			int min_val = INT_MAX;
			int pos = 0;
			int i=0;
			while(i<n){
				if(lists[i]){
					count++;
					if(lists[i]->val < min_val){
						pos = i;
						min_val = lists[i]->val;
					}
				}
				i++;
			}
			ListNode* tmp = lists[pos];
			if(tmp){
				lists[pos] = tmp->next;
				tmp->next = t->next;
				t->next = tmp;
				t = t->next; 
			}
			
		}
		int i = 0;
		while(i<lists.size()){
			if(lists[i]){
				t->next = lists[i];
				break;
			}
			i++;		
		}
		return p->next;    
    }*/
    ListNode* mergeKLists(vector<ListNode*>& lists){
    	int length = lists.size();
    	if(length==0)
    		return NULL;
    	if(length==1)
    		return lists[0];
    	int mid = (length-1)/2;
    	ListNode* l1 = mergeKLists(lists.subList(0,mid+1));
    	ListNode* l2 = mergeKLists(lists.subList(mid+1,length));
    	
    	return mergeTwoLists(l1,l2);
    }
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
	int a[] = {1,5,9,14};
	int b[] = {2,4,8,13};
//	int c[] = {3,6,7,12};
//	int d[] = {10,11};
	vector<int> v1(a,a+4);
	vector<int> v2(b,b+4);
//	vector<int> v3(c,c+4);
//	vector<int> v4(d,d+2);
	Solution s;
	ListNode* t1 = NULL;// = s.creatList(v1);
	ListNode* t2 = NULL;// = s.creatList(v2);
//	ListNode* t3 = s.creatList(v3);
//	ListNode* t4 = s.creatList(v4);
	vector<ListNode*> vec;
	vec.push_back(t1);
	vec.push_back(t2);
//	vec.push_back(t3);
//	vec.push_back(t4);
	ListNode* p = s.mergeKLists(vec);
	s.Print(p);
	return 0;
} 
