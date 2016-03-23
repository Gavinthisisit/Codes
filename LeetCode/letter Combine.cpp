#include <iostream>
#include <vector>
#include <string>

using namespace std;



class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
    }
    void combine(string s1,string s2,vector<string> retval){
		int n = s1.length();
		int m = s2.length();
		int i,j;
		if(n==0 && m !=0){
			for(i=0;i<m;i++){
				retval.push_back(s2[i]);
			}
		}
		else if(n!=0 && m == 0){
			for(i=0;i<n;i++){
				retval.push_back(s1[i]);
			}
		}
		else if(m!=0 && n!=0){
			for(i=0;i<m;i++){
				for(j=0;j<m;j++){
					retval.push_back(s)
				}
			}
		}
		
    }
};


int main(){
	return 0;
}
