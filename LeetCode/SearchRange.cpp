#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        int i;
        int flag = 0;
        vector<int> retval;
        retval.clear();
        for(i=0;i<n;i++){
        	if(target < A[i])
				break;
			else if(target > A[i])
				continue; 
			if(flag ==0 && A[i] == target){
				if( A[i+1] != target){			//只有一个target 
					retval.push_back(i);
					flag += 1;	
				}	
				retval.push_back(i);
				flag += 1;
			}
			else if(A[i] == target && A[i+1] != target){
				flag += 1;
				retval.push_back(i);
			}
				
			if(flag == 2)
				break;
			
        }
        if(!flag){
        	retval.push_back(-1);
        	retval.push_back(-1);
        }
        return retval;
    }
};


int main(){
	int a [] = {0,0,0,0,2,2,3,3,4,4,5,5,5,6,7,7,8,9,9,9,10};
	
	Solution s;
	
	vector<int> v;
	
	v = s.searchRange(a,21,10);
	int i = 0;
	while(i<v.size()){
		cout<<v[i++]<<",";
	}
	cout<<endl;
	return 0;
}
