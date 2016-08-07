#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
	int nthSuperUglyNumber(int n, vector<int>& primes) {
		if (n <= 0)
			return 0;
		int *uglynum = new int[n]();
		int size = primes.size();
		int *point = new int[size]();
		int i = 0;
		while (i < size){
			point[i] = 0;
			++i;
		}
		uglynum[0] = 1;
		int count = 1;
		while (count < n){
			int uglymin = get_min(uglynum, point, primes);
			uglynum[count] = uglymin;
			for (int j = 0; j < primes.size(); ++j){
				while (uglynum[point[j]] * primes[j] <= uglymin)
					++point[j];
			}
			++count;
		}
		return uglynum[n - 1];
	}
	int get_min(int* a, int* b, vector<int> primes){
		int min = INT_MAX;
		int i = 0;
		while (i < primes.size()){
			int tmp = a[b[i]] * primes[i];
			if (tmp < min)
				min = tmp;
			++i;
		}
		return min;
	}
};


int main(){
	Solution s;
	int a[] = { 2, 7, 13, 19 };
	vector<int> vec(a, a + 4);
	cout << s.nthSuperUglyNumber(12, vec) << endl;
	return 0;
}