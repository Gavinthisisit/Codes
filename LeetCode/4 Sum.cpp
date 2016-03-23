#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
private:
	vector<vector<int> >  retval;	
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int i,j,k,h;
		retval.clear();
        if(num.size()<4)
        	return retval;
//        set<vector<int> > tmpres;
        sort(num.begin(),num.end());
        for(i=0;i<num.size();i++){
        	
        	if(num[i] > target/4)
        		break;
        	if(i-1>=0 && num[i] == num[i-1])
        		continue;
        	for(j=i+1;j<num.size();j++){
        		if(j>i+1 && num[j] == num[j-1])
        			continue;
        		k = j+1;
        		h = num.size()-1;
        		while(k<h){
        			 if(k>j+1 && num[k] == num[k-1]){
        			 	k++;
						continue;		
					 }
					 if(h+1<num.size() && num[h] == num[h+1]){
					 	h--;
					 	continue;
					 }
					 int t1 = num[i];
					 int t2 = num[j];
					 int t3 = num[k];
					 int t4 = num[h];

					 int sum = num[i]+num[j]+num[k]+num[h];
					 
					 if(sum > target)
					 	h--;
					else if(sum < target)
						k++;
					else{
						vector<int>  ret;
						ret.push_back(num[i]);
						ret.push_back(num[j]);
						ret.push_back(num[k]);
						ret.push_back(num[h]);
						retval.push_back(ret);
						k++;
					}
				
        		}
        	}
        }
        return retval;
    }
};


int main(){
	int a[] = {0,4,-5,2,-2,4,2,-1,4};
	vector<int> vec(a,a+9);
	Solution s;
	vector<vector<int> > retval;
	retval = s.fourSum(vec,12);
	int i,j;
	for(i=0;i<retval.size();i++){
		for(j=0;j<retval[i].size()-1;j++){
			cout<<retval[i][j]<<",";
		}
		cout<<retval[i][j]<<endl;
	}
	return 0;
}
