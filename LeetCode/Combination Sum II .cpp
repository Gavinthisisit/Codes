#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


/*    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
    	int i,j,k;
    	vector<vector<int> > retval;
		vector<int>	ret;
		sort(num.begin(),num.end());
		bool flag1;
		bool flag2;
		for(i=0;i<num.size();i++){
			ret.clear();
			if(i>0 && num[i] == num[i-1])			//前半部分，两数重复，去掉后面的数
				continue;
			if(num[i] == target){
				ret.push_back(num[i]);
				retval.push_back(ret);
				continue;
			}	
 			j = i+1;
			k = num.size()-1;
			if(j==k){
				if(num[i]+num[j] == target){
					ret.clear();
    				ret.push_back(num[i]);
    				ret.push_back(num[j]);
    				retval.push_back(ret);	
				}
			}
			flag1 = 0;
			flag2 = 0;
			while(j<k){
				if(j > i+1 && num[j] == num[j-1]){	 //前半部分，两数重复，去掉后面的数
					j++;
					continue;
				}
				if(k<num.size()-1 && num[k]==num[k+1]){  
                    k--;  
                    continue;  
                }
    			if(num[i]+num[j] == target && !flag1){
    				ret.clear();
    				ret.push_back(num[i]);
    				ret.push_back(num[j]);
    				retval.push_back(ret);
					flag1 = 1;
    			}
				if(num[k] != num[j]){
					if(num[i]+num[k] == target && !flag2){
    					ret.clear();
    					ret.push_back(num[i]);
    					ret.push_back(num[k]);
    					retval.push_back(ret);
						flag2 = 1;
    				}
				}
				int sum = num[i]+num[j]+num[k];
				if(sum < target )
					j++;
				else if(sum > target)
					k--;
				else{
					ret.clear();
					ret.push_back(num[i]);
					ret.push_back(num[j]);
					ret.push_back(num[k]);
					retval.push_back(ret);
					j++;
				}
			}
		}
		return retval;
	}*/
class Solution {
private:
	vector<vector<int> > retval;
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        int i = 0;
		retval.clear();
		vector<int> path;
		if(!num.size())
			return retval;
/*		if(num.size() == 1)
			if(num[0] == target){
				path.push_back(num[0]);
				retval.push_back(path);
			}
			else
				return retval;*/
				
		sort(num.begin(),num.end());
		
		while(i<num.size()){
			if(i >0 && num[i] == num[i-1]){
				i++;
				continue;
			}
			path.clear();
			path.push_back(num[i]);
			dfs(num,i+1,target,path,retval,num[i],0);
			i++;
		}
		vec_clear(retval);
		return retval;
    }
	void dfs(vector<int> &v,int pos,int target,vector<int> &path,vector<vector<int> > &retval,int sum,int dep){
		if(sum > target){
			return;
		}
		if(sum == target){
			retval.push_back(path);
			return;
		}
		int i;
		for(i=pos;i<v.size();i++){
			if(sum+v[i] == target){
				path.push_back(v[i]);
				retval.push_back(path);
				path.pop_back();
				break;
			}
			else if(sum+v[i] < target){
				path.push_back(v[i]);
				dfs(v,i+1,target,path,retval,sum+v[i],dep+1);
				path.pop_back();
			}
			else
				break;
		}
		return;
	}
	void vec_clear(vector<vector<int> > &vec){
		int i,j;
		i = 0;
		while(i<vec.size()){
			j = i+1;
			while(j<vec.size()){
				if(vec[i] == vec[j]){
					vector<vector<int> >::iterator iter = vec.begin()+j;
					vec.erase(iter);
				}
				else
					j++;
			}
			i++;
		}
	}
};


int main(){
	int a[] = {4,4,2,1,4,2,2,1,3};
	vector<int> vec(a,a+9);
	vector<vector<int> >  retval;	
	Solution s;
	retval = s.combinationSum2(vec,6);
	int i,j;
	for(i=0;i<retval.size();i++){
		for(j=0;j<retval[i].size();j++)
			cout<<retval[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
	
	return 0;
}
