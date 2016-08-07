#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int lengthOfLastWord(string s) {
		int len = s.size()-1;
		if (len < 0)
			return 0;
		while (s[len] == ' ' && len >=0)
			--len;
		if (len < 0)
			return 0;
		int i = 0;
		while (len >= 0 && s[len] != ' '){
			--len;
			++i;
		}
			
		return i;
	}
};

int main(){
	string s1 = "a";
	Solution s;
	cout << s.lengthOfLastWord(s1) << endl;
	return 0;
}