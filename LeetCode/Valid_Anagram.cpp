#include <iostream>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
    	int n = s.length();
    	if(s.length()!=t.length())
    		return false;
		for(int i=0;i<n;i++){
			if(s[i]!=t[n-1-i])
				return false;
		}	    
		return true;
    }
};

int main(){
	return 0;
} 
