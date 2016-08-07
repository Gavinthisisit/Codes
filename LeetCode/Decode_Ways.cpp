#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		int len = s.size();
		if (!len)
			return 0;
		if (s[0] == '0')
			return 0;
		int* dp = new int[len+1];
		memset(dp, 0, sizeof(int)*(len+1));
		dp[0] = 1;
		dp[1] = 1;
		for (int i = 2; i <= len; ++i){
			if (s[i-1] != '0')
				dp[i] = dp[i - 1];
			if (s[i - 2] != '0' &&  s.substr(i-2,2) <= "26"){
				dp[i] += dp[i - 2];
			}
				
		}
		int retval =  dp[len];
		delete[] dp;
		return retval;
	}

	//Time Exceeded
	void dfs(string s,int pos,int &count){
		if (pos == s.size()){
			++count;
			return;
		}
		dfs(s, pos + 1, count);

		if ((pos <s.size()-1) && s[pos] <= '2' && s.substr(pos, 2) <= "26")
			dfs(s, pos + 2, count);
		return;
			
	}
};

int main(){
	Solution s;
	cout << s.numDecodings("1159314227869675749153973158896359637455398771636981264557866779635662185364345272665484523344457179") << endl;
	return 0;

}