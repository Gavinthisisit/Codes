#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
    	vector<vector<int> > retval;
		vector<int> path;
		dfs(retval,path,k,1,0,n);
		return retval;    
    }
    void dfs(vector<vector<int> > &retval,vector<int> &path,int MaxDep,int start,int dep,int n){
    	if(dep == MaxDep){
    		retval.push_back(path);
    		return;
    	}
    	int i;
    	for(i=start;i<=n;i++){
    		path.push_back(i);
    		dfs(retval,path,MaxDep,i+1,dep+1,n);
    		path.pop_back();
    	}
    }
};


int main()
{
	Solution s;
    vector< vector<int> > vec = s.combine(5, 3);
    for (int i = 0; i < vec.size(); ++i)
    {
        for (int j = 0; j < vec[0].size(); ++j)
        {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
