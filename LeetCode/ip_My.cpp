#include <iostream>
#include <vector>
#include <string>


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
			if(start == s.size()){
			int beg = 0;
			string addr;
				for(i=0;i<4;i++){
					string ip(s,beg,pos[i]-beg+1);
					beg = pos[i]+1;
					
					addr += i==0?ip:"."+ip;
				}
				retval.push_back(addr);
			}
			return;
		}
/*		for(i=start;i<s.size() && i-start+1<4;i++){
			if(Check(s,start,i)){
				pos[dep] = i;
				dfs(s,i+1,dep+1);
			}
		}*/
		
		if(Check(s,start,start)){			//只取一位
			pos[dep] = start;
			dfs(s,start+1,dep+1);	
		}
		if(start+2 <= s.size() && Check(s,start,start+1)){			//取两位
			pos[dep] = start+1;
			dfs(s,start+2,dep+1);
		}
		if(start+3 <= s.size() && Check(s,start,start+2)){	      //取三位
			pos[dep] = start+2;
			dfs(s,start+3,dep+1);
		}
	}
};

int main(){
	string s  = "1001001";
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
	//string str = "1001001";
	vector<string> vec;
	Solution s1;
	vec = s1.restoreIpAddresses(s);
	int i = 0;
	while(i<vec.size()){
		cout<<vec[i]<<endl;
		i++;
	}
	return 0;
}

