#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void dfsCreat(vector<vector<int> >& retval,vector<int>& tmp,int pos,int k,int &count,int n){
    	if(k==0){
    		if(count==n)
    			retval.push_back(tmp);
    		return;
    	}
    	for(int i=pos;i<=9;i++){
    		if(count+i > n || i>n/k)
    			break;
    		else{
    			tmp.push_back(i);
    			count += i;
    			dfsCreat(retval,tmp,i+1,k-1,count,n);
    			tmp.pop_back();
    			count -= i;
    		}
    	}
    }
    vector<vector<int> > combinationSum3(int k, int n){
    	vector<vector<int> > retval;
		vector<int> tmp;
		
		int sum = 0;
		
		dfsCreat(retval,tmp,1,k,sum,n);
		
		return retval;	
    }
    
};

int main(){
	Solution s;
	vector<vector<int> > ret = s.combinationSum3(2,18);
	for(int i=0;i<ret.size();i++){
		for(int j=0;j<ret[0].size();j++)
			cout<<ret[i][j]<<" ";
		cout<<endl;
	}
		
	return 0;
} 
