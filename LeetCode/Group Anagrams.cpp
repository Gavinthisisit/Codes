#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

	class Solution {
	public:
	    vector<vector<string> > groupAnagrams(vector<string>& strs) {
	    	vector<vector<string> > retval;
			if(strs.size()==0)
				return retval;
			map<int,vector<string> > m;
			for(int i=0;i<strs.size();i++){
				int tmp = 0;
				for(int j=0;j<strs[i].length();j++){
					int bi = 1;
					tmp |= bi<<(strs[i][j]-'a');		
				}
				if(strs[i][0]==strs[i][1] && strs[i][0] != strs[i][2]){
					if(strs[i][0] > strs[i][2]){
						int bi = 1;
						tmp |= bi<<30;
					}else{
						int bi = 1;
						tmp |= bi<<29;
					}
				}
				else if(strs[i][0]==strs[i][2] && strs[i][0]!= strs[i][1]){
					if(strs[i][0] > strs[i][1]){
						int bi = 1;
						tmp |= bi<<30;
					}else{
						int bi = 1;
						tmp |= bi<<29;
					}
				}
				else if(strs[i][1]==strs[i][2] && strs[i][1]!=strs[i][0]){
					if(strs[i][0] < strs[i][2]){
						int bi = 1;
						tmp |= bi<<30;
					}else{
						int bi = 1;
						tmp |= bi<<29;
					}
				}
				else if(strs[i][1]==strs[i][2] && strs[i][0]==strs[i][1]){
					int bi = 1;
					tmp |= bi<<30;
					tmp |= bi<<29;	
				} 
				if(m.find(tmp) != m.end())
					m[tmp].push_back(strs[i]);
				else{
					vector<string> t;
					t.push_back(strs[i]);
					m.insert(pair<int,vector<string> >(tmp,t));
				}
					
			}
			map<int,vector<string> >::iterator ite;
			for(ite=m.begin();ite!=m.end();ite++){
				retval.push_back(ite->second);
			}
			for(int i=0;i<retval.size();i++){
				sort(retval[i].begin(),retval[i].end());
			}   
			return retval;
	    }
	};


int main(){
	Solution s;
	string str[] = {"too","tot"};
	vector<string> vec(str,str+54);
	vector<vector<string> > ret = s.groupAnagrams(vec);
	for(int i=0;i<ret.size();i++){
		for(int j=0;j<ret[i].size();j++){
			cout<<ret[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
