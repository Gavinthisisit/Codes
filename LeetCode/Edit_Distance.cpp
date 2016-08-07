#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int len1 = word1.size()+1;
		int len2 = word2.size()+1;
		if (!len2)
			return len1;
		if (!len1)
			return len2;
		int **dis = new int*[len1];
		for (int i = 0; i < len1; ++i)
			dis[i] = new int[len2];
		for (int i = 0; i < len1; ++i)
			dis[i][0] = i;
		for (int i = 0; i < len2; ++i)
			dis[0][i] = i;
		for (int i = 1; i < len1; ++i)
			for (int j = 1; j < len2; ++j){
				if (word1[i - 1] == word2[j - 1])
					dis[i][j] = dis[i - 1][j - 1];
				else
					dis[i][j] = min(dis[i - 1][j - 1] + 1, min(dis[i - 1][j] + 1, dis[i][j - 1] + 1));
			}
			int retval =  dis[len1 - 1][len2 - 1];
			for (int i = 0; i < len1; ++i)
				delete[]dis[i];
			delete[]dis;
			return retval;
	}
};



int main(){
	Solution s;
	cout << s.minDistance("b", "a") << endl;
	return 0;
}