#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<int> diffWaysToCompute(string input) {
		return dfsCompute(input);
	}
	vector<int> dfsCompute(string str){
		vector<int> result;
		for (int i = 0; i < str.length(); ++i){
			if (str[i] == '+' || str[i] == '-' || str[i] == '*'){
				vector<int> left = dfsCompute(str.substr(0, i));
				vector<int> right = dfsCompute(str.substr(i + 1));
				for (int j = 0; j < left.size(); ++j){
					for (int k = 0; k < right.size(); ++k){
						if (str[i] == '+')
							result.push_back(left[j] + right[k]);
						else if (str[i] == '-')
							result.push_back(left[j] - right[k]);
						else
							result.push_back(left[j] * right[k]);
					}
				}
			}
		}
		if (result.empty())
			result.push_back(atoi(str.c_str()));
		return result;
	}
};

int main(){
	Solution s;
	string ss = "2*3-4*5";
	vector<int> vec = s.diffWaysToCompute(ss);
	for (int i = 0; i < vec.size(); ++i)
		cout << vec[i] << " ";
	cout << endl;
	return 0;
}

