#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> retval;
		if (!n)
			return retval;
		dfsGenerate(retval, n, 0, "");
		return retval;
	}

	void dfsGenerate(vector<string> &ret, int len, int tag,string str){
		if (str.size() == len * 2){
			ret.push_back(str);
			return;
		}
		if (tag > 0){
			str += ")";
			tag -= 1;
			dfsGenerate(ret, len, tag, str);
			str = str.substr(0, str.size() - 1);
			tag += 1;
		}
		if (tag + str.size() < len * 2){
			str += "(";
			tag += 1;
			dfsGenerate(ret, len, tag, str);
			str = str.substr(0, str.size() - 1);
			tag -= 1;
		}
		return;
	}
};


int main(){
	Solution s;
	vector<string> ret = s.generateParenthesis(3);
	for (int i = 0; i < ret.size(); ++i)
		cout << ret[i] << endl;
	return 0;
}