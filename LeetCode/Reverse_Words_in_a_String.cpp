#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	void reverseWords(string &s) {
		if (s.empty())
			return;
		
		int i = 0;
		while (s[i] == ' ')
			++i;
		s = s.substr(i, s.size());
		int n = s.size()-1;
		while (s[n] == ' ')
			--n;
		s = s.substr(0, n+1);
		i = 0;
		string retval = "";
		int pos = 0;
		while (i < s.size()){
			if (s[i] == ' '){
				string tmp = s.substr(pos, i - pos);
				tmp = ' ' + tmp;
				retval = tmp + retval;
				while (s[i] == ' ')
					++i;
				pos = i;
			}
			else
				++i;
		}
		retval = s.substr(pos, i - pos) + retval;
		s = retval;
	}
};
int main(){
	Solution sl;
	string s = "   a   b ";
	sl.reverseWords(s);
	cout<<":"<< s <<":"<<endl;
	return 0;
}