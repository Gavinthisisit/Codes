#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
	int nthUglyNumber(int n)
	{
		if (n <= 0)
			return 0;
		int *uglyNum = new int[n]();
		int *uglyNum2 = uglyNum;
		int *uglyNum3 = uglyNum;
		int *uglyNum5 = uglyNum;
		uglyNum[0] = 1;
		int count = 1;
		while (count < n)
		{
			int curUgly = min(min(*uglyNum2 * 2, *uglyNum3 * 3), *uglyNum5 * 5);
			uglyNum[count] = curUgly;
			while (*uglyNum2 * 2 <= curUgly)
				uglyNum2++;
			while (*uglyNum3 * 3 <= curUgly)
				uglyNum3++;
			while (*uglyNum5 * 5 <= curUgly)
				uglyNum5++;
			count++;
		}
		int result = uglyNum[n - 1];
		delete[] uglyNum;
		return result;

	}

	int nthUglyNumber_2(int n){
		if (n <= 0)
			return 0;
		int *uglynum = new int[n]();
		int *uglynum2 = uglynum;
		int *uglynum3 = uglynum;
		int *uglynum5 = uglynum;

		uglynum[0] = 1;
		int count = 1;
		while (count < n){
			int uglymin = min(min(*uglynum2 * 2, *uglynum3 * 3), *uglynum5 * 5);
			uglynum[count] = uglymin;
			while (uglymin >= *uglynum2 * 2)
				++uglynum2;
			while (uglymin >= *uglynum3 * 3)
				++uglynum3;
			while (uglymin >= *uglynum5 * 5)
				++uglynum5;
			++count;
		}
		int result = uglynum[n - 1];
		delete[] uglynum;
		return result;
	}
};



int main(){
	Solution s;
	cout << s.nthUglyNumber(20) << endl;
	return 0;
}