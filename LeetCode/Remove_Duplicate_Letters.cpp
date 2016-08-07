#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
	string removeDuplicateLetters(string s){
		bool flag[26];
		memset(flag, false, 26*sizeof(bool));
		int count = 0;
		int i = 0;
		while (i < s.size()&& count<26){
			int t = s[i] - 'a';
			if (!flag[t]){
				flag[t] = 1;
				++count;
			}
			++i;
		}
		i = 0;
		string retval = "";
		while (i < 26){
			if (flag[i]){
				char tmp = i + 'a';
				string str(1, tmp);
				retval += str;
			}
			++i;
		}
		return retval;
	}
};


int main(){
	Solution s;
	cout << s.removeDuplicateLetters("")<< endl;
	return 0;
}