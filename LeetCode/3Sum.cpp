#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
    	int i,j,k;
    	vector<vector<int> > retval;
		retval.clear();
		vector<int>	ret;
		sort(num.begin(),num.end());
		for(i=0;i<num.size();i++){
			int n = num[i];
			if(i>0 && num[i] == num[i-1])			//前半部分，两数重复，去掉后面的数
				continue;	
 			j = i+1;
			k = num.size()-1;
			while(j<k){
				ret.clear();
				if(j > i+1 && num[j] == num[j-1]){	 //前半部分，两数重复，去掉后面的数
					j++;
					continue;
				}
				if(k<num.size()-1 && num[k]==num[k+1]){  
                    k--;  
                    continue;  
                }
				int target = num[i]+num[j]+num[k];
				if(target < 0 )
					j++;
				else if(target > 0)
					k--;
				else{
					ret.push_back(n);
					ret.push_back(num[j]);
					ret.push_back(num[k]);
					retval.push_back(ret);
					j++;
				}
			}
		}
		return retval;
	}

};


int main(){
	int a[] = {-1,0,1,2,-1,-4,3};
	vector<int> vec(a,a+7);
	vector<vector<int> >  retval;	
	Solution s;
	retval = s.threeSum(vec);
	int i,j;
	for(i=0;i<retval.size();i++){
		for(j=0;j<retval[i].size();j++)
			cout<<retval[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	
	return 0;
}
