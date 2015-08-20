#include <iostream>
#include <map>

using namespace std;

/*
class Solution {
public:
    bool isIsomorphic(string s, string t) {
  		return check(s,t) && check(t,s);	      
    }
    bool check(string s,string t){
    	int n = s.length();
  		map<char,char> m;
		for(int i=0;i<n;i++){
			if(m.find(s[i]) != m.end()){
				if(m[s[i]] != t[i])
					return false;
			}		
			else{
				m.insert(pair<char,char>(s[i],t[i]));
			}
				
			
		}
		return true;
    }
};*/


class Solution{
public:
	bool isIsomorphic(string s,string t){
		int hash[256] = {0};
		int hash1[256] = {0};
//		string tmp = "";
		
		for(int i=0;i<s.length();i++){
			if(hash[s[i]] == 0)
				hash[s[i]] = t[i];
			else
				if(hash[s[i]] != t[i])
					return false;
			if(hash1[t[i]] == 0)
				hash1[t[i]] = s[i];
			else
				if(hash1[t[i]] != s[i])
					return false;
//			tmp.push_back(hash[s[i]]);
		}
		return true;
	}
};

int main(){
	string s1 = "aa";
	string s2 = "bb";
	Solution s;
	cout<<s.isIsomorphic(s1,s2);
	return 0;
} 
