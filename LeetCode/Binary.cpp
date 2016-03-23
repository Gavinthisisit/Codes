#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int m = a.size()-1;
        int n = b.size()-1;
        string retval = "";
        string flag = "0";
        while(m>=0 && n>=0){
        	string tmp1(a,m,1);
			string tmp2(b,n,1);
			string tmp = tmp1+tmp2+flag;
			if(tmp=="111"){
				flag = "1";
				retval += "1";
			}
			else if(tmp=="110" || tmp=="101" || tmp=="011"){
				flag = "1";
				retval += "0"; 
			}
			else if(tmp == "000"){
				flag = "0";
				retval += "0";
			}
			else{
				flag = "0";
				retval += "1";
			}
			m--;
			n--;	  
        }
        while(n>=0){
        	string tmp1(b,n,1);
        	string tmp =tmp1+flag;
			if(tmp=="11"){
				flag = "1";
				retval += "1"; 
			}
			else if(tmp=="00"){
				flag = "0";
				retval += "0"; 
			}
			else{
				flag = "0";
				retval += "1";
			} 
			n--;		 
        }
		while(m>=0){
        	string tmp1(a,m,1);
        	string tmp =tmp1+flag;
			if(tmp=="11"){
				flag = "1";
				retval += "0"; 
			}
			else if(tmp=="00"){
				flag = "0";
				retval += "0"; 
			}
			else{
				flag = "0";
				retval += "1";
			} 
			m--;		 
    	}
    	if(flag == "1")
    		retval += flag;
    	string retstr;
    	m = retval.size()-1;
    	while(m>=0){
    		string s(retval,m,1);
    		retstr += s;
    		m--;
    	}
    	return retstr;
    }
};




int main(){
	string a = "11";
	string b = "1";
	Solution s;
	string str = s.addBinary(a,b);
/*	int m;
	m  = 2; 
	string t(a,5,1);*/
	cout<<str<<endl;
	return 0;
}
