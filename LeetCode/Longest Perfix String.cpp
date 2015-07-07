#include <iostream>
#include <vector>
#include <string>

using namespace std;



class Solution{


public:
	string longestCommonPerfix(vector<string> &strs){
		int i;
		int pos;
		bool flag = false;
		int min = 2147483646;
		int str_num;
//		vector<string>::iterator it;
		for(i=0;i<strs.size();i++){
			if(min > strs[i].length()){
				min = strs[i].length();
				str_num = i;
			}
				
		}
		if(strs.size()!=0){
			pos = min;
			while(min>0){
				flag = false;
				char ch = strs[str_num][min-1];
				for(i=0;i<strs.size();i++){
					if(ch != strs[i][min-1]){
						min -= 1;
						pos = min;		
						str_num = i;
						flag = true;
						break;
					}
				}
				if(!flag)
					min -= 1;
			}
			
			string tmp = strs[str_num];
			string retval = tmp.substr(0,pos);
			return retval;
		}
		else
			return "";

	}		
};

int main(){
	vector<string> strs;
//	strs = ["flower","flow","flight"];
	string s = "flower";
	strs.push_back(s);
	s = "flight";
	strs.push_back(s);
	s = "flow";
	strs.push_back(s);
/*	vector<string>::iterator it;
	int i;
	for(i=0;i<strs.size();i++)
		cout<<strs[i].length()<<"  ";
	cout<<endl;
	cout<<strs.size()<<endl;
	cout<<strs[0]<<endl;
	cout<<strs[0].length()<<endl;
	cout<<s[1]<<endl;
	cout<<strs[0][1]<<endl;*/
	Solution so;
	cout<<so.longestCommonPerfix(strs)<<endl;
	return 0;
}

