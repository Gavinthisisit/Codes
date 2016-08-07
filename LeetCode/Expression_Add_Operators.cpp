#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	vector<string> addOperators(string num, double  target) {
		vector<string> retval;
		dfsFind(num, 0, 0, retval, "", target, 'p');
		return retval;
	}
	void dfsFind(string num, double result, double preret, vector<string>& ret,string tmp,double target,char preas){
		int len = num.size();
		if (!len && target == result){
			ret.push_back(tmp);
			return;
		}
		for (int i = 1; i <= len; ++i){
			string fac = num.substr(0, i);
			if (fac.size() > 1 && fac[0] == '0')
				return;
			int currentNum = string2int(fac);
			string leftnum = num.substr(i);
			if (tmp.size() != 0){
				if (preas == '+')
					dfsFind(leftnum, (result - preret) + preret*currentNum, preret*currentNum, ret, tmp + "*" + fac, target,preas);
				else if (preas == '-')
					dfsFind(leftnum, (result + preret) - preret*currentNum, preret*currentNum, ret, tmp + "*" + fac, target, preas);
				else
					dfsFind(leftnum, result*currentNum, currentNum, ret, tmp + "*" + fac, target, preas);
				dfsFind(leftnum, result + currentNum, currentNum, ret, tmp + "+" + fac, target, '+');
				dfsFind(leftnum, result - currentNum, currentNum, ret, tmp + "-" + fac, target, '-');
			}
			else{
				dfsFind(leftnum, currentNum, currentNum, ret, fac, target, preas);
			}
		}

	}
	int string2int(string num){
		int len = num.size();
		int i = 0;
		double retval = 0;
		while (i < len){
			retval = retval * 10 + num[i] - '0';
			++i;
		}
		return retval;
	}
};

int main(){
	Solution s;
	string a = "2147483648";
	vector<string> vec;
	vec = s.addOperators(a, -2147483648.0);
	for (int i = 0; i < vec.size(); ++i)
		cout << vec[i] << "  ";
	cout << endl;
	return 0;
}