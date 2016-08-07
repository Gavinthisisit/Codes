#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
//	bool flag[101][101];	
	bool isInterleave(string s1, string s2, string s3){
		int l1 = s1.size();
		int l2 = s2.size();
		int l3 = s3.size();
		if (l3 != (l1 + l2))
			return false;
		if (!l3)
			return true;
		bool **flag;
		flag = new bool*[l1 + 1];
		for (int i = 0; i <= l1; ++i)
			flag[i] = new bool[l2+1];
		for (int i = 0; i <= l1; ++i){
			for (int j = 0; j <= l2; ++j)
				flag[i][j] = false;
		}
		for (int i = 0; i < l1; ++i){
			if (s1[i] == s3[i])
				flag[i+1][0] = true;
			else
				break;
		}
		for (int j = 0; j < l2; ++j){
			if (s2[j] == s3[j])
				flag[0][j+1] = true;
			else
				break;
		}
		for (int i = 1; i <= l1; ++i){
			for (int j = 1; j <= l2; ++j){
				if (s1[i - 1] == s3[i + j - 1])
					flag[i][j] = flag[i - 1][j] || flag[i][j];
				if (s2[j - 1] == s3[i + j - 1])
					flag[i][j] = flag[i][j - 1] || flag[i][j];
			}
		}
		bool retval =  flag[l1][l2];
		return retval;
	}
};



int main(){
	Solution s;
	string s1 = "aabcc";
	string s2 = "dbbca";
	string s3 = "aadbbbaccc";
	cout << s.isInterleave(s1, s2, s3) << endl;
	return 0;

}