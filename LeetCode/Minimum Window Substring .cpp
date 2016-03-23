#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        
    }
    string string_map(string s,string t){
    	int i;
    	map<char,int> sm;
    	for(i=0;i<t.length();i++){
    		sm.insert(pair<char,int>(t[i],0));
    	}
    	int behind,before;
    	behind = s.length()-1;
    	before = 0;
    	
    	
    }
    bool isMatch(char c,string t){
    	map<char,int>::iterator itor;
    	bool flag = 0;
    	int i = 0;
    	while(i<t.length()){
    		if(t[i] == c){
    			flag = 1;
    			return 1;
    		}
    	}
    	if(!flag)
    		return 0;
    }
};

int main(){
	return 0;
}
