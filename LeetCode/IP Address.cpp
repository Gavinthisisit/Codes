#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>

using namespace std;


class Solution {
private:
	int pos[4];
	vector<string> retval;
public:
    vector<string> restoreIpAddresses(string s) {
        retval.clear();
		dfs(s,0,0);
		return retval;
    }
 /*   void checkLeage(vector<string> val,string s,int start,int count,int pos,string ret){
    	int len = lengthCheck(s,n);
    	
    	if(len > (5-pos)*3)
    		return;
    		
    	if(pos == 4){
    		int tmp = Check(s.substr(n,s.length()));
    		if(!tmp)
    			return ;
			char aa[5];
			itoa(tmp,aa,10);
			string ss(&aa[0],&aa[strlen(aa)]);
			ret = ret+"."+ss;
			val.push_back(ret);
			return;	
    	}
    	ret = ret+"."+s.substr(n,n+count);
    	checkLeage(val,s,n+1,1,pos+1,ret);
    	checkLeage(val,s,n+2,2,pos+1,ret);
    	if(Check(s.substr(n,n+3)))
    		checkLeage(val,s,n+3,3,pos+1,ret);	
    }
    int lengthCheck(string s,int n){
    	int i;
    	int count = 1;
    	for(i=n;i<s.length();i++){
    		if(s[i] != '0')
    			count++;
    	}
    	return count;
    	
    }*/
    int Check(string s,int start,int end){
	    string ip(s,start,end-start+1);
		if(ip.size()==1)
			return ip>="0" && ip<="9";
		else if(ip.size()==2)
			return ip>="10" && ip<="99";
		else if(ip.size()==3)
			return ip>="100" && ip<="255";
		else 
			return false;
    }
	void dfs(string s,int start,int dep){
		int i = 0;
		if(dep == 4){
			if(end == s.size()){
			int beg = 0;
				for(i=0;i<4;i++){
					string ip(s,begin,pos[i]-beg+1);
					beg = pos[i]+1;
					
					ip += i==0?ip:"."+ip;
				}
				retval.push_back(ip);
			}
		}
	/*	for(i=start;i<s.size() && i-start+1<4;i++){
			if(Check(s,start,i)){
				pos[dep] = i;
				dfs(s,i+1,dep+1);
			}
		}
	*/
	if(Check(s,start,start)){			//只取一位
		pos[dep] = start;
		dfs(s,start,dep+1);	
	}
	if(Check(s,start,start+1)){			//取两位
		pos[dep] = start+1;
		def(s,start+1,dep+1);
	}
	if(Check(s,start,start+2))	      //取三位
		pos[dep] = start+2;
		dfs(s,start+2,dep+1);
	}
};

int main(){
	string s  = "25525511135";
/*	string a1 = s.substr(2,3);
	int i = 0;
	int tmp = 0;
	char a[1];
	while(i<a1.length()){
		a[0] = a1[i];
		tmp = tmp*10+atoi(a);
		i++;
	}
//	cout<<tmp<<endl;
	char aa[5];
	itoa(tmp,aa,10);
	string ss(&aa[0],&aa[strlen(aa)]);
	cout<<ss<<endl;
	cout<<a1<<endl;*/
	Solution s1;
	vector<string> vec;
	
	vec = s1.restoreIpAddresses(s);
	
		
	return 0;
}
