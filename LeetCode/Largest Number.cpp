#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int> &num) {
        vector<string> vec_str;
        int i = 0;
        while(i<num.size()){
        	stringstream ss;
        	ss<<num[i];
        	string str = ss.str();
        	vec_str.push_back(str);
        	i++;
        }
        string retval;
        i = 0;
        sort_str1(vec_str);
   //     sort_str2(vec_str);
        i = 0;
        bool flag = 0;
        while(i<vec_str.size()){
        	if(vec_str[i] != "0")
        		flag = 1;
        	retval += vec_str[i];
        	i++;
        }
        if(!flag)
        	return "0";
        else 
			return retval;
    }
    void sort_str1(vector<string> &str){
    	int i,j;
    	bool flag = 1;
    	for(i=0;i<str.size() && flag;i++){
			flag = 0;
			for(j=0;j<str.size()-i-1;j++){
				string s1 = str[j];
				string s2 = str[j+1];
				if(compare(s1,s2)){
					string tmp = str[j];
					str[j] = str[j+1];
					str[j+1] = tmp;
					flag = 1;
				}	
			}
		}
    }
/*    void sort_str2(vector<string> &str){
    	int i,j;
    	bool flag = 1;
    	for(i=0;i<str.size() && flag;i++){
    		flag = 0;
			for(j=0;j<str.size()-1;j++){
				string s1 = str[j];
				string s2 = str[j+1];
				if(s1[0] == s2[0]){
					int k = 1;
					bool flag1 = 0;
					int len1 = s1.length();
					int len2 = s2.length();
					while(k < len1 && k < len2){
						if(s1[k] < s2[k]){
							str[j] = s2;
							str[j+1] = s1;
							flag1 = 1;
							flag = 1;
							break;
						}
						else if(s1[k] >s2[k]){
							flag1 = 1;
							break;
						}
						else
							k++;
					}
					if(!flag1){
						k = len2;
						while(k <len1){
							if(s2[0] > s1[k]){
								str[j] = s2;
								str[j+1] = s1;
								flag = 1;
								break;
							}
							else if(s2[0] < s1[len2]){
								break;
							}
							else
								k++;
						}
					}
					
				}	
			}
		}
    }*/
    bool compare(string s1,string s2){
    	string tmp1 = s1+s2;
		string tmp2 = s2+s1;
		if(tmp1 < tmp2)
			return true;
		else
			return false;	 
	}
};



int main(){
	int a[] = {0,0};
	vector<int> vec(a,a+2);
	Solution s;
	string str = s.largestNumber(vec);
	cout<<str<<endl;
	return 0;
}
