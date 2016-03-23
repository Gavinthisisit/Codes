#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int numTrees(int n) {
    	vector<int> vec;
    	vec.push_back(1);
    	for(int i=1;i<=n;i++){
    		vec.push_back(0);			//为vec扩展空间用
			if(i<3)
				vec[i] = i;
			else{
				for(int j=1;j<=i;j++)
					vec[i] += vec[j-1]*vec[i-j];
			} 
    	}
    	return vec[n];
    }
    
};



int main(){
	Solution s;
	cout<<s.numTrees(5);
	return 0;
}
