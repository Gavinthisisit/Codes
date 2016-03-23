#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 **/
struct RandomListNode {
    int label;
    RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
    	if(head==NULL)
			return NULL;
		RandomListNode* p = head;
		RandomListNode* retval = new RandomListNode(p->label);
		retval->next = p->next;
		p->next = retval;
		p = p->next->next;
		while(p!=NULL){
			RandomListNode* tmp = new RandomListNode(p->label);
			tmp->next = p->next;
			p->next = tmp;
			p = p->next->next;
		}
		p = head;
		while(p!=NULL){
			if(p->random)
				p->next->random = p->random->next;
			p = p->next->next; 
		}
		p = head;
		while(p!=NULL){
    		cout<<p->label<<" ";
    		if(p->random!=NULL)
    			cout<<p->random->label<<endl;
    		else
    			cout<<endl;
    		
    		p = p->next;	
    	}
				
		RandomListNode* ret = retval;
		p = head;
		while(ret->next){
			p->next = p->next->next;
			ret->next = ret->next->next;
			
			p = p->next;
			ret = ret->next;
		}
		p->next = NULL;
		ret->next = NULL;
		
		
/*		while(p!=NULL){
			if(p->random!=NULL){
				RandomListNode* tmp = head;
				RandomListNode* mmp = retval; 
				while(tmp!=NULL){
					if(tmp==p->random){
						ret->random = mmp;
						break;
					}
					tmp = tmp->next;
					mmp = mmp->next;	
				}
			}
			p = p->next;
			ret = ret->next; 
		}
*/
		return retval;    
    }
    RandomListNode* creatList(vector<int>& v){
    	if(v.size()==0)
    		return NULL;
    	RandomListNode* retval = new RandomListNode(v[0]);
    	RandomListNode* ret = retval;
    	int i = 1;
    	
    	while(i<v.size()){
    		RandomListNode* tmp = new RandomListNode(v[i]);
    		ret->next = tmp;
    		ret = ret->next; 
    		i++;
    	}
    	RandomListNode* tmp;
    	ret = retval;
    	ret->random = ret->next->next;
    	ret = ret->next->next;
    	ret->random = retval->next;
    	tmp = ret->next;
    	tmp->random = ret;
    	ret = tmp->next->next->next;
    	tmp = tmp->next;
    	ret->random = tmp; 
    
    	return retval;
    }
    void Print(RandomListNode* t){
    	while(t!=NULL){
    		cout<<t->label<<" ";
    		if(t->random!=NULL)
    			cout<<t->random->label<<endl;
    		else
    			cout<<endl;
    		
    		t = t->next;
    		
    	}
    }
    
};

int main(){
	int a[] = {1,2,3,4,5,6,7,8};
	vector<int> v(a,a+8);
	Solution s;
	RandomListNode* root;
	root = s.creatList(v);
	cout<<&root<<endl;
	s.Print(root);
	cout<<endl;
	RandomListNode* p = s.copyRandomList(root);
	cout<<&p<<endl;
	s.Print(p);
	return 0;
}

