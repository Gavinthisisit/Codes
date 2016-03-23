#include <iostream>
#include <vector>

using namespace std;
 
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
    	vector<vector<int> > vec;
		if(numRows==0)
			return vec;
		int i = 1;
		while(i<=numRows){
			vector<int> tmp;
			if(i==1){
				tmp.push_back(1);
				vec.push_back(tmp);
				i++;
				continue;
			}
			int j = 0;
			while(j<i){
				int a,b;
				if(j-1<0)
					a = 0;
				else
					a = vec[i-2][j-1];
				if(j>=vec[i-2].size())
					b = 0;
				else
					b = vec[i-2][j];
				tmp.push_back(a+b);
				j++;
			}
			vec.push_back(tmp);
			i++;
		}
		return vec;	    
    }
};



int main(){
	vector<vector<int> > vec;
	Solution s;
	vec = s.generate(20);
	for(int i=0;i<vec.size();i++){
		for(int j=0;j<vec[i].size();j++)
			cout<<vec[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
