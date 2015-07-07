#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
    	int i,j;
    	vector<int> ret;
    	vector<vector<int> > retval;
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				ret.clear();
				ret.push_back(i);
				ret.push_back(j);
				retval.push_back(ret);				
			}
		}  
		return retval;  
    }
    vector<vector<int> > combine(int n,int k){
    	
    }
    void dfs(int n,int k,vector<int> path,int i){
    	
    }
};


int main(){
	Solution s;
	retval = s.combine(4,2);
	int i,j;
	for(i=0;i<retval.size();i++){
		for(j=0;j<retval[i].size();j++)
			cout<<retval[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	
	return 0;
}
