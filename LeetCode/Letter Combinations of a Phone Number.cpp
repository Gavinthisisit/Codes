#include <iostream>
#include <vector>
#include <string>

using namespace std;



class Solution {
public:
    vector<string> letterCombinations(string digits) {
       vector<string> retval;
       if(digits.length()==0)
    		return retval;
    	string map[10];
    	map[0] = "";
    	map[1] = "";
    	map[2] = "abc";
    	map[3] = "def";
    	map[4] = "ghi";
    	map[5] = "jkl";
    	map[6] = "mno";
    	map[7] = "pqrs";
    	map[8] = "tuv";
    	map[9] = "wxyz";
    	char tmp[100];
    	dfs(digits,tmp,retval,0,map);
	   return retval; 
    }
    
    void dfs(string digits,char* tmp,vector<string>& retval,int dep,string* map){
    	
    	if(dep == digits.length()){
    		string s(tmp,dep);
//    		string s = getString(tmp,digits.length());
    		retval.push_back(s);
    		return;
    	}
    	char pos = digits[dep];
    	for(int i=0;i<map[pos-'0'].length();i++){
    		tmp[dep] = map[pos-'0'][i];
    		dfs(digits,tmp,retval,dep+1,map);
    	}
    		
    }
    string getString(char* v,int n){
    	string rets(v,n);
    	return rets;
    }
    
};



int main(){
	char s[] = {'2','d','f'};
	string t[] = {"dlskjds","daksa","dsakjhds"};
	Solution so;
	vector<string> v;
	v = so.letterCombinations("234");
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<endl; 
//	getString(t,3);

	return 0;
}
