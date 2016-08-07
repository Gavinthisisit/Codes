#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1.empty() && s2.empty())
			return true;
		return match(s1, s2);
	}
	bool match(string a1, string a2){
		int len1, len2;
		len1 = a1.size();
		len2 = a2.size();
		if (len1 != len2)
			return false;
		if ((len1 == 1))
			return a1 == a2;
		string st1 = a1, st2 = a2;
		sort(st1.begin(), st1.end());
		sort(st2.begin(), st2.end());
		if (st2 != st1)
			return false;
		string s11, s12, s21, s22;
		bool res = false;
		for (int i = 1; i < len1 && !res; ++i) {
			s11 = a1.substr(0, i);
			s12 = a1.substr(i, len1 - i);
			s21 = a2.substr(0, i);
			s22 = a2.substr(i, len1 - i);
			res = isScramble(s11, s21) && isScramble(s12, s22);
			if (!res) {
				s21 = a2.substr(0, len1 - i);
				s22 = a2.substr(len1 - i, i);
				res = isScramble(s11, s22) && isScramble(s12, s21);
			}
		}
		return res;
	}
};

/*
class Solution {
public:
	bool isScramble(string s1, string s2) {
		int l1 = s1.length();
		int l2 = s2.length();
		if (l1 != l2) return false;
		if (l1 == 1) return s1 == s2;
		string st1 = s1, st2 = s2;
		sort(st1.begin(), st1.end());
		sort(st2.begin(), st2.end());
		for (int i = 0; i < l1; ++i) {
			if (st1[i] != st2[i]) {
				return false;
			}
		}
		string s11, s12, s21, s22;
		bool res = false;
		for (int i = 1; i < l1 && !res; ++i) {
			s11 = s1.substr(0, i);
			s12 = s1.substr(i, l1 - i);
			s21 = s2.substr(0, i);
			s22 = s2.substr(i, l1 - i);
			res = isScramble(s11, s21) && isScramble(s12, s22);
			if (!res) {
				s21 = s2.substr(0, l1 - i);
				s22 = s2.substr(l1 - i, i);
				res = isScramble(s11, s22) && isScramble(s12, s21);
			}
		}
		return res;
	}
};
*/
int main(){
	string s1 = "abb";
	string s2 = "bab";
	Solution s;
	cout << s.isScramble(s1, s2) << endl;
	return 0;
}