#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
  		if(matrix.size()==0)
		  return;
		vector<int> row;
		vector<int> col;
		int i,j;
		for(i=0;i<matrix.size();i++)
			row.push_back(0);
		for(j=0;j<matrix[0].size();j++)
				col.push_back(0);
		for(i=0;i<matrix.size();i++){
			for(j=0;j<matrix[i].size();j++){
				if(matrix[i][j]==0){
					row[i] = 1;
					col[j] = 1;
				}
			}
		}
		for(i=0;i<matrix.size();i++){
			for(j=0;j<matrix[i].size();j++){
				if(row[i]==1 || col[j]==1){
					matrix[i][j] = 0;
				}
			}
		}
		 
    }
};

int main(){
	int a[] = {1,2,3,1};
	int b[] = {1,0,1,3};
	int c[] = {1,2,1,4};
	int d[] = {1,3,4,7};
	vector<int> v1(a,a+4);
	vector<int> v2(b,b+4);
	vector<int> v3(c,c+4);
	vector<int> v4(d,d+4);
	vector<vector<int> > vec;
	vec.push_back(v1);
	vec.push_back(v2);
	vec.push_back(v3);
	vec.push_back(v4);
	Solution s;
	s.setZeroes(vec);
	for(int i=0;i<vec.size();i++){
			for(int j=0;j<vec[i].size();j++){
				cout<<vec[i][j]<<" ";
			}
			cout<<endl;
		}
	return 0;
} 
