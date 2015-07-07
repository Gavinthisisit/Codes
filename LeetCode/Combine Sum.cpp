#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > retval;
        vector<int> path;
        sort(candidates);
		path.clear();
		retval.clear();					//vector¿âÖÐµÄÅÅÐòº¯Êý 
        search(candidates,path,0,target,0,retval);
        return retval;
    }
    void search(vector<int> &candidate,vector<int> &path,int index,int target,int sum,vector<vector<int> > &retval){
    	if(sum > target)
			return;
		if(target == sum){
			retval.push_back(path);
			return;
		}
		int i;
		for(i = index;i<candidate.size();i++){
			path.push_back(candidate[i]);
			search(candidate,path,i,target,sum+candidate[i],retval);
			path.pop_back();
		}	
    }
    void sort(vector<int> &a){
    	int i,j;
    	bool flag = 1;
    	for(i=0;i<a.size() && flag;i++){
    		flag = 0;
    		for(j=0;j<a.size()-i-1;j++){
    			if(a[j] > a[j+1]){
    				int tmp = a[j];
    				a[j] = a[j+1];
    				a[j+1] = tmp;
    				flag = 1;
    			}	
    		}
    	}
    }
};


int main(){
	int a[] = {2,3,6,7};
	vector<int> vec(a,a+4);
	Solution s;
	vector<vector<int> > retval;
	retval = s.combinationSum(vec,7);
	int i,j;
	for(i=0;i<retval.size();i++){
		for(j=0;j<retval[i].size()-1;j++){
			cout<<retval[i][j]<<",";
		}
		cout<<retval[i][j]<<endl;
	}
	 
	return 0;
}
