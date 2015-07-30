#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
    	vector<int> retval;
		if(rowIndex<0)
			return retval;
		int i;
		for(i=0;i<=rowIndex;i++)
			retval.push_back(0);
		for(i=0;i<=rowIndex;i++){
			retval[rowIndex] = 1;
			for(int j=rowIndex-1;j>0;j--)
				retval[j] = retval[j]+retval[j-1];
			retval[0] = 1;
		}    
    }
};

int main(){
	Solution s;
	vector<int> vec;
	vec = s.getRow(4);
	for(int i=0;i<vec.size();i++)
		cout<<vec[i]<<" ";
	return 0;
} 
