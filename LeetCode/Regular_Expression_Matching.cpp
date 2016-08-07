#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	bool isMatch(const string& _s, const string& _p) {
		const char *s = _s.c_str();
		const char *p = _p.c_str();
		if (s == NULL ||  p == NULL)
			return true;
		if (*s == '\0')
			return *p == '\0';
		if (*(p + 1) == '*'){
			while ((*s != '\0' && *p == '.') || *s == *p){
				if (isMatch(string(s), string(p + 2)))
					return true;
				++s;
			}
			return isMatch(string(s), string(p + 2));
		}
		else if ((*s != '\0' && *p == '.') || *s == *p){
			return isMatch(string(s + 1), string(p + 1));
		}
		return false;
	}
	bool isMatch_2(const char *s, const char *p)
	{
		if (s == NULL || p == NULL) return false;
		if (*p == '\0') return *s == '\0';
		// ".*" matches "", so we can't check (*s == '\0') here.

		if (*(p + 1) == '*')
		{
			// Here *p != '\0', so this condition equals with
			// (*s != '\0' && (*p == '.' || *s == *p)).
			while ((*s != '\0' && *p == '.') || *s == *p)
			{
				if (isMatch(s, p + 2)) return true;
				++s;
			}

			return isMatch(s, p + 2);
		}
		else if ((*s != '\0' && *p == '.') || *s == *p)
		{
			return isMatch(s + 1, p + 1);
		}

		return false;
	}
	bool isMatch_3(const char *s, const char *p) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function    
		int len1 = 0;
		for (const char* q = s; *q != '\0' && q != NULL; ++q) len1++;
		int len2 = 0;
		for (const char* q = p; *q != '\0' && q != NULL; ++q) len2++;

		vector<vector<bool> > f(len1 + 1, vector<bool>(len2 + 1, false));
		f[0][0] = true;
		for (int i = 0; i <= len1; ++i)
		{
			char preChar = '\0';
			int preIdx = 0;
			for (int j = 1; j <= len2; ++j)
			{
				if (i >= 1 && (p[j - 1] == '.' || s[i - 1] == p[j - 1])) f[i][j] = f[i - 1][j - 1];
				else if (p[j - 1] == '*')
				{
					if (i >= 1 && (preChar == s[i - 1] || preChar == '.')) f[i][j] = f[i - 1][j] || f[i][j - 1];
					f[i][j] = f[i][j] || f[i][preIdx];
					//f[i-1][j] = f[i-1][j] || f[i-1][preIdx];
				}
				if (p[j - 1] != '*') preChar = p[j - 1], preIdx = j - 1;
			}
		}

		return f[len1][len2];
	}

};


int main(){
	Solution s;
	string s1 = "a";
	string s2 = "ab*";
	cout << s.isMatch(s1, s2) << endl;
	cout << s.isMatch_2(s1.c_str(), s2.c_str()) << endl;
	cout << s.isMatch_3(s1.c_str(), s2.c_str()) << endl;
	return 0;
}