#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int row = matrix.size();
		int col = matrix[0].size();
		if (!row && !col)
			return false;
		return binary(matrix, 0,  row - 1,0, col - 1, target);
	}
	bool BinarySearch(vector<int> vec, int target, int start, int end){
		if (start > end)
			return false;
		int mid = (start + end) / 2;
		if (target == vec[mid])
			return true;
		else if (target > vec[mid])
			return BinarySearch(vec, target, mid + 1, end);
		else
			return BinarySearch(vec, target, start, mid - 1);
	}
	bool MatrixDivide(vector<vector<int> >& vec, int row, int col, int hrow, int hcol, int target){
		int mid_row = (row + hrow) / 2;
		int mid_col = (col + hcol) / 2;
		if (row > hrow || col > hcol)
			return false;
		if (row == hrow && col == hcol){
			return target == vec[row][col];
		}
		if (target == vec[mid_row][mid_col])
			return true;
		else if (target < vec[mid_row][mid_col]){
			return MatrixDivide(vec, row, col, mid_row - 1, hcol, target) || MatrixDivide(vec, row, col, hrow, mid_col - 1, target);
		}
		else
			return MatrixDivide(vec, mid_row+1, col, hrow, hcol, target) || MatrixDivide(vec, row, mid_col+1, hrow, hcol, target);
	}
	bool searchMatrix_2(vector<vector<int> >& metrix, int target){
		int row = metrix.size();
		int col = metrix.size();
		if (!row || !col)
			return false;

	}
	bool binary(vector<vector<int> >& vec, int row, int hrow, int col, int hcol, int target){
		if (row == hrow || col == hcol)
			return BinarySearchMatrix(vec, row, hrow, col, hcol, target);
		int tmp = vec[row][hcol];
		if (tmp == target)
			return true;
		else if (tmp > target)
			return binary(vec, row, hrow, col, hcol - 1, target);
		else
			return binary(vec, row+1, hrow, col, hcol, target);
	}
	bool BinarySearchMatrix(vector<vector<int> >& vec, int row, int hrow, int col ,int hcol, int target){
		if (row == hrow){
			if (col > hcol)
				return false;
			int mid = (col + hcol) / 2;
			int tmp = vec[row][mid];
			if (tmp == target)
				return true;
			else if (tmp > target)
				return BinarySearchMatrix(vec, row, hrow, col, mid - 1, target);
			else
				return BinarySearchMatrix(vec, row, hrow, mid+1, hcol, target);
		}
		else{
			if (row > hrow)
				return false;
			int mid = (row + hrow) / 2;
			int tmp = vec[mid][col];
			if (tmp == target)
				return true;
			else if (tmp > target)
				return BinarySearchMatrix(vec, row, mid-1, col, hcol, target);
			else
				return BinarySearchMatrix(vec, mid+1, hrow, col, hcol, target);
		}
		
	}
};


int main(){
	int a1[] = { 1, 4, 7, 11, 15 };
	int a2[] = { 2, 5, 8, 12, 19 };
	int a3[] = { 3, 6, 9, 16, 22 };
	int a4[] = { 10, 13, 14, 17, 24 };
	int a5[] = { 18, 21, 23, 26, 30 };
	vector<int> v1(a1, a1 + 5);
	vector<int> v2(a2, a2 + 5);
	vector<int> v3(a3, a3 + 5);
	vector<int> v4(a4, a4 + 5);
	vector<int> v5(a5, a5 + 5);

	vector<vector<int> > vec;
	vec.push_back(v1);
	vec.push_back(v2);
	vec.push_back(v3);
	vec.push_back(v4);
	vec.push_back(v5);
	Solution s;
	cout << s.searchMatrix(vec, 20) << endl;
	return 0;
}