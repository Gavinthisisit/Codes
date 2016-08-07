#include <iostream>
#include <string>

using namespace std;

string retval[100000];
static int cnt = 1;

class Solution {
public:
	string countAndSay(int n) {
		if (n <= cnt)
			return "1";
		else{
			string p =  (cnt-1)?retval[cnt-1]:"1";
			while (n > cnt){
				p = convertStirng(p);
				retval[++cnt] = p;
			}
			return p;
		}
	}
	string convertStirng(const string& ss){
		int len = ss.size();
		if (!len)
			return "";
		string ret = "";
		int i = 0;
		while (i < len){
			int count = 0;
			char s1 = ss[i++];
			++count;
			while (ss[i] == s1){
				++i;
				++count;
			}
			string tmp = "xx";
			if (count == 1){
				tmp[0] = 1 + '0';
				tmp[1] = s1;
			}
			else{
				tmp[0] = count + '0';
				tmp[1] = s1;
			}
			ret = ret + tmp;	
		}
		return ret;
	}
};


int main(){
	Solution s;
	cout << s.countAndSay(6) << endl;
	return 0;
}