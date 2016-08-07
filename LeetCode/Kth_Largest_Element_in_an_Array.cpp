#include <iostream>
#include <vector>
#include <time.h>
#include <Windows.h>

using namespace std;

class Solution {
public:
	int findKthLargest(vector<int>& nums, int k) {
		if (k > nums.size())
			return -1;
		return qsortQuery(0, nums.size() - 1, k, nums);
	}
	int qsortQuery(int start, int end, int kth,vector<int>& nums){
		if (start > end)
			return -1;
		else if (start == end)
			return nums[start];
		int pos = qsort(nums,start, end);
		if ((end - pos) < kth){
			kth = kth - (end - pos);
			end = pos;
		}
		else{
			start = pos + 1;
		}
		qsortQuery(start,end,kth,nums);

	}
	int qsort(vector<int>& vec, int start, int end){
		if (start > end)
			return -1;
		int key = vec[start];
		while (start < end){
			while (start < end && key <= vec[end])
				--end;
			vec[start] = vec[end];
			while (start < end && vec[start] <= key)
				++start;
			vec[end] = vec[start];
		}
		vec[start] = key;
		return start;
	}
};

int main(){
	time_t t_start, t_end;
	t_start = clock();
	Solution s;
	int a[] = { 3, 2, 1, 5, 6, 4, 4 };
	vector<int> vec(a, a + 7);
	t_end = clock();
	cout <<(t_end- t_start)<<endl;
	cout << s.findKthLargest(vec, 4)<<endl;
	return 0;
}