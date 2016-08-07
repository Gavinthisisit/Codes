#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.empty())
			return "";
		string retval =  Palindrome(s);
		return retval;
	}

	string Palindrome(string s){
		bool flag[1000][1000] = {false};
		int len = s.size();
		int i = 0;
		int j = 0;
		int max = 0;
		int pos = 0;
		while (i < len){
			flag[i][i] = 1;
			max = 1;
			pos = i;
			++i;
		}
		for (i = 0; i < len; ++i){
			if (s[i] == s[i + 1]){
				flag[i][i + 1] = 1;
				max = 2;
				pos = i;
			}
		}
		for (int j = 3; j <= len; ++j){
			for (int i = 0; i < len - j + 1; ++i){
				int p = i + j - 1;
				if (s[i] == s[p] && flag[i + 1][p - 1]){
					flag[i][j] = 1;
					max = j;
					pos = i;
				}
			}
		}
		return s.substr(pos, max);
	}
};


int main(){
	Solution s;
	string str = "bananas";
	cout << s.longestPalindrome(str) << endl;
	return 0;
}