#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.empty())
			return 0;
		int len = s.size();
		char *stack = new char[len];
		memset(stack, ' ', len);
		int pos = -1;
		int i = 0;
		int count = 0;
		while (i < len){
			if (s[i] == '(')
				stack[++pos] = s[i];
			else if (s[i] == ')'){
				if (stack[pos] == '('){
					--pos;
					count += 2;
				}
				else{
					--pos;
				}
			}
			++i;
		}
		return count;
	}
};


int main(){
	Solution s;
	string s1 = ")()(((())))(";
	cout << s.longestValidParentheses(s1) << endl;
	return 0;
}