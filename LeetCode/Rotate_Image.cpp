#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
    	int n = matrix.size();
    	if(n==0)
			return;
		int mid = n/2;
		int i=0;
							//沿中线垂直翻转 
		while(i<mid){
			for(int j=0;j<n;j++){
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[n-i-1][j];
				matrix[n-i-1][j] = tmp;
			}
			i++;
		}
		for(i=1;i<matrix.size();i++){
			for(int j=0;j<i;j++){
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[j][i];
				matrix[j][i] = tmp;
			}
		}    
    }
};


int main(){
	int a[] = {1,3,5,7};
	int b[] = {10,11,16,20};
	int c[] = {23,30,34,50};
	int d[] = {33,33,33,44};
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
	s.rotate(vec);
	
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++)
			cout<<vec[i][j]<<" ";
		cout<<endl; 
	}
	return 0;
	
} 
