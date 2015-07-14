#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
        int size = triangle.size();
   //     int len = triangle[0].size();
        if(size==0)
        	return 0;
        for(int i=1;i<size;i++)
        	for(int j=0;j<triangle[i].size();j++){
        		if(j==0)
        			triangle[i][j] = triangle[i][j] + triangle[i-1][j];
        		else if(j==triangle[i].size()-1)
        			triangle[i][j] = triangle[i][j] + triangle[i-1][j-1];
        		else{
        			if(triangle[i][j]+triangle[i-1][j-1] < triangle[i][j]+triangle[i-1][j])
        				triangle[i][j] = triangle[i-1][j-1]+triangle[i][j];
        			else
        				triangle[i][j] = triangle[i][j]+triangle[i-1][j];
				}
        	}
        int min_path = triangle[size-1][0];
        for(int j=1;j<triangle[size-1].size();j++){
        	int t = triangle[size-1][j];
        	if(min_path > triangle[size-1][j])
        		min_path = triangle[size-1][j];
        }
        	
        return min_path;
    }
};

int main(){
	int a[] = {2};
	int b[] = {3,4};
	int c[] = {6,5,7};
	int d[] = {4,1,8,3};
	vector<int> v1(a,a+1);
	vector<int> v2(b,b+2);
	vector<int> v3(c,c+3);
	vector<int> v4(d,d+4);
	vector<vector<int> > vec;
	vec.push_back(v1);
	vec.push_back(v2);
	vec.push_back(v3);
	vec.push_back(v4);
	Solution s;
	cout<<s.minimumTotal(vec);
	return 0;
};

