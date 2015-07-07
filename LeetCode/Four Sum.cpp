#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &candidates, int target) {
        vector<vector<int> > retval;
        vector<int> path;
//        sort(candidates);
		sort(candidates.begin(),candidates.end());
		path.clear();
		retval.clear();					//vector¿âÖĞµÄÅÅĞòº¯Êı 
        search(candidates,path,0,target,0,0,retval);
        return retval;
    }
    void search(vector<int> &candidate,vector<int> &path,int index,int target,int deep,int sum,vector<vector<int> > &retval){
    	if(sum > target)
			return;
		if(deep == 4){
			if(target == sum){
				retval.push_back(path);
				return;
			}
			else 
				return;
		}
		
		int i;
		for(i = index;i<candidate.size();i++){
			int t = candidate[i];
			path.push_back(candidate[i]);
			search(candidate,path,i+1,target,deep+1,sum+candidate[i],retval);
			path.pop_back();
		}	
    }
/*    map<int,pair<int,int> > m_pair(vector<int> a){
    	int i,j,count;
    	count = 0;
    	for(i=0;i<a.size();i++){
    		for()    	
		}
    }
*/
};




int main(){
	int a[] = {1,0,-1,0,-2,2};
	vector<int> vec(a,a+6);
	Solution s;
	vector<vector<int> > retval;
	retval = s.fourSum(vec,0);
	int i,j;
	for(i=0;i<retval.size();i++){
		for(j=0;j<retval[i].size()-1;j++){
			cout<<retval[i][j]<<",";
		}
		cout<<retval[i][j]<<endl;
	}
/*	map<int,pair<int,int> >  m;
	m[1] = pair<int,int>(3,5);
	cout<<m[1].first<<endl; */
	return 0;
}
