#include <iostream>
#include <vector>
#include <map>

using namespace std;
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
    	int i,j,k;
    	vector<vector<int> > retval;
		vector<int>	ret;
		sort(num);
		for(i=0;i<num.size();i++){
			int n = num[i];
			if(i-1>=0 && num[i] == num[i-1])
				continue;
			j = i;
			k = num.size()-1;	
			int target = 0 - n;
			while(j<k){
				ret.clear();
				if(num[j]+num[k] < target)
					j++;
				else if(num[j]+num[k] > target)
					k--;
				else{
					ret.push_back(n);
					ret.push_back(num[j]);
					ret.push_back(num[k]);
					retval.push_back(ret);
					j++;
					k++;
				}
			}
		}
		return retval;	    
    }
    void sort(vector<int> &a){
    	int i,j;
    	bool flag = 1;
    	for(i=0;i<a.size() && flag;i++){
    		flag = 0;
    		for(j=0;j<a.size()-i-1;j++){
    			if(a[j] > a[j+1]){
    				int tmp = a[j];
    				a[j] = a[j+1];
    				a[j+1] = tmp;
    				flag = 1;
    			}	
    		}
    	}
    }
};


int main(){
	int a[] = {-1,0,1,2,-1,-4};
	vector<int> vec(a,a+6);
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

