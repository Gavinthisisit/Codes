#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		int len = nums.size();
		if (!len)
			return 0;
		int* Lis = new int[len];
		memset(Lis, 0, len);
		Lis[1] = nums[0];
		int retval = 1;
		for (int i = 1; i < len; ++i){
			int j;
			if (Lis[retval] < nums[i])
				j = ++retval;
			else
				j = BinarySearch(Lis, 1, retval, nums[i]) + 1;
			Lis[j] = nums[i];
		}
		return retval;
	}
	int BinarySearch(int* num,int low,int high,int key){
		
		while (low <= high){
			int mid = (low + high) >> 1;
			if (key > num[mid] && key <= num[mid + 1])
				return mid;
			else if (key > num[mid])
				low = mid + 1;
			else
				high = mid - 1;

		}
		return 0;
	}
};


int main(){
	int a[] = { 2, 9, 2, 5, 3, 7, 101, 18 };
	vector<int> vec(a, a + 8);
	Solution s;
	cout << s.lengthOfLIS(vec) << endl;
	return 0;
}