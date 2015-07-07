#include <iostream>
#include <vector>
using namespace std;

#define MaxSize 120

class Solution {
public:
    int uniquePaths(int m, int n) {
        int i,j;
		int path[MaxSize];
		
		for(i=0;i<m;i++)
			path[i] = 1;


		for(i=1;i<m;i++)
			for(j=1;j<n;j++)
				path[j] += path[j-1];
		return path[m-1];
    }
};

int main(){
	Solution s;
	cout<<s.uniquePaths(3,7)<<endl;
	return 0;
}

