#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

/*
class Solution {
public:
	int calculate(string s) {
		int len = s.size();
		if (!len)
			return 0;
		string *queue = new string[len];
		int i = 0;
		int head = -1, tail = 0;
		while (i < len){
			if (s[i] == ' '){
				++i;
				continue;
			}
			if (s[i] == '*'){
				while (s[++i] == ' ')
					continue;
				int num1 = string2int(queue[--tail]);
				int k = 0;
				int pos = i;
				while (s[i] >= '0' && s[i] <= '9'){
					++k;
					++i;
				}
				string tmp = s.substr(pos, k);
				int num2 = string2int(tmp);
				int count = num1 * num2;
				string ret = int2string(count);
				queue[tail++] = ret;
			}
			else if (s[i] == '/'){
				while (s[++i] == ' ')
					continue;
				int num1 = string2int(queue[--tail]);
				int k = 0;
				int pos = i;
				while (s[i] >= '0' && s[i] <= '9'){
					++k;
					++i;
				}
				string tmp = s.substr(pos, k);
				int num2 = string2int(tmp);
				int count = num1 / num2;
				string ret = int2string(count);
				queue[tail++] = ret;
			}
			else if (s[i] == '+' || s[i] == '-'){
				queue[tail++] = s[i];
				++i;
			}
			else {
				int k = 0;
				int pos = i;
				while (s[i] >= '0' && s[i] <= '9'){
					++k;
					++i;
				}	
				string tmp = s.substr(pos, k);
				queue[tail++] = tmp;
			}
		}
		int retval = 0;
		while (head < tail-1){
			if (head == -1){
				int num2 = string2int(queue[++head]);
				retval += num2;
			}
			else{
				if (queue[++head] == "+"){
					int num2 = string2int(queue[++head]);
					retval += num2;
				}
				else{
					int num2 = string2int(queue[++head]);
					retval -= num2;
				}
			}
		}
		delete[]queue;
		return retval;
	}
	int string2int(string s){
		int  i = 0;
		int retval = 0;
		while (i < s.size()){
			int tmp = s[i] - '0';
			retval = retval*10 + tmp;
			++i;
		}
		return retval;
	}
	string int2string(int x){
		stringstream ss;
		ss << x;
		string retval;
		ss >> retval;
		return retval;
	}
};
*/

class Solution {
public:
	int calculate(string s) {
		istringstream in(s);
		long long  retval=0,tmp,sign=1,num;
		in >> tmp;
		char op;
		bool flag = 0;
		while (in >> op){
			if (op == '+' || op == '-'){
				retval += sign*tmp;
				flag = 1;
				sign = 44 - op;
				in >> tmp;
			}
			else{
				in >> num;
				if (op == '*')
					tmp *= num;
				else
					tmp /= num;
			}
		}
		return flag?retval:tmp;
	}
};

int main(){
	string s1 = "1*2-3/4+5*6-7*8+9/10";
	Solution s;
	cout << s.calculate(s1) << endl;
/*	string p = "123";
	string p1 = "9";
	string ss = "1*2-3/4+5*6-7*8+9/10.01";
	istringstream is(ss);
	char str;
	while (is >> str)
		cout << str << endl;*/
	return 0;
}