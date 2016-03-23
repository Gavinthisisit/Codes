#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
 /*       int n = num.size();
        int first = num[0];
 //       bool flag = 0;
        if(first < num[n-1]){
//        	flag = 0;
        	return first;
        }
        int head = 0;
        int tail = n-1;
        int mid = (head+tail)/2;
        if(num[mid] == first){
        	int i = 1;
        	while(i<num.size()){
        		if(num[i] < num[i-1])
					return num[i]; 
				i++;
        	}
			if(i==num.size())
				return first;			       	
        }
        while(head != tail){
			mid = (head+tail)/2;
        	if(num[mid] < num[mid-1] && num[mid] <= num[mid+1]){
        		return num[mid];
        	}
        	else if(num[mid] > first){
        		head = mid+1;
        	}
        	else if(num[mid] < first){
        		tail = mid;
        	}	
        }
        return num[head];
    }*/
    int i=1;
    int n = num.size();
    if(n==1)
    	return num[0];
    if(num[0] <num[n-1])
    	return num[0];
    while(i<num.size()){
    	if(num[i]<num[i-1] && num[i] <num[(i+1)/n])
    		return num[i];
    	i++;
    }
    if(i == n)
    	return num[0];
}
};


int main(){
	
	int a[] = {1,2,1};
	
	vector<int> v(a,a+3);
	
	Solution s;
	
	cout<<s.findMin(v)<<endl;
	
	return 0;
	
}


