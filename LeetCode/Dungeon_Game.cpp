#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int row = dungeon.size();
		int col = dungeon[0].size();
		
		if (!row || !col)
			return 0;
		
		int** minHealth = new int*[row];
		for (int i = 0; i < row; ++i)
			minHealth[i] = new int[col];
		minHealth[0][0] = dungeon[0][0];

		for (int i = 0; i < row; ++i){
			for (int j = 0; j < col; ++j){
				if (!i && !j)
					continue;
				if (i == 0){
					dungeon[i][j] += dungeon[i][j - 1];
					if (dungeon[i][j] < minHealth[i][j-1])
						minHealth[i][j] = dungeon[i][j];
					else
						minHealth[i][j] = minHealth[i][j - 1];
				}
				else if (j == 0){
					dungeon[i][j] += dungeon[i-1][j];
					if (dungeon[i][j] < minHealth[i-1][j])
						minHealth[i][j] = dungeon[i][j];
					else
						minHealth[i][j] = minHealth[i-1][j];
				}
				else{
					int tmp = dungeon[i][j];
					dungeon[i][j] = max(dungeon[i - 1][j], dungeon[i][j - 1]) + dungeon[i][j];
					if (minHealth[i - 1][j] > minHealth[i][j - 1]){
						int p = dungeon[i - 1][j] + tmp;
						if (p < minHealth[i - 1][j])
							minHealth[i][j] = p;
						else
							minHealth[i][j] = minHealth[i-1][j];
					}
					else{
						int p = dungeon[i][j-1] + tmp;
						if (p < minHealth[i][j - 1])
							minHealth[i][j] = p;
						else
							minHealth[i][j - 1];
					}
				}
			}
		}
		int retval =  minHealth[row - 1][col - 1];
		for (int i = 0; i < col; ++i)
			delete[] minHealth[i];
		delete[] minHealth;
		if (retval >= 0)
			return 1;
		else
			return 1 - retval;
	}
};


int main(){
	int a[] = { -2, -3, 3  };
	int b[] = { -5, -10, 1 };
	int c[] = { 10, 30, -5 };
	vector<int> aa(a, a + 3);
	vector<int> bb(b, b + 3);
	vector<int> cc(c, c + 3);
	vector<vector<int> > vec;
	vec.push_back(aa);
	vec.push_back(bb);
	vec.push_back(cc);
	Solution s;
	cout << s.calculateMinimumHP(vec) << endl;
	return 0;
}