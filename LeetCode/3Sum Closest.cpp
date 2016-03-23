#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;
/*
class Solution {
private:
	int min;		
public:
    int threeSumClosest(vector<int> &num, int target) {
    	int i,j,k;
    	int retval;
		sort(num.begin(),num.end());
		int flag = 0;
		min  = 65535;
		for(i=0;i<num.size();i++){
			int n = num[i];
			if(i>0 && num[i] == num[i-1])			//前半部分，两数重复，去掉后面的数
				continue;	
 			j = i+1;
			k = num.size()-1;
			
			while(j<num.size()-1){
				if(j > i+1 && num[j] == num[j-1]){	 //前半部分，两数重复，去掉后面的数
					j++;
					continue;
				}
				while(k<num.size()){
					if(k<num.size()-1 && num[k]==num[k+1]){  
	                    k++;  
	                    continue;  
	                }
	                int sum = num[i]+num[j]+num[k];
	                	if(sum < target){
							if(flag == 0){
								min = target - sum;
								retval = sum;
								flag = 1;
							}
							else if(min < target-sum){
								min = target-sum;
								retval =  sum;
							}
							k++;		
						}
						else if(target < sum){
							if(flag == 0){
								if(sum - target < min)
									return sum;
							}
							else{
								if(sum-target < min){
									min = sum-target; 
									retval = sum;
								}	
							}
							k++;	
						}	
						else{
							return retval;
						}
				}
				
			}
		}
		return retval;
	}		    
};
*/

class Solution {
private:
	int min;
public:
    int threeSumClosest(vector<int> &num, int target) {
    	int i,j,k;
		int retval;
		int flag = 0;
		sort(num.begin(),num.end());
		min = 65535;
		for(i=0;i<num.size();i++){
			j = i+1;
			k = num.size()-1;
			while(j<k){
				if(j>i+1 && num[j] == num[j-1]){
					j++;
					continue;
				}
				int sum = num[i]+num[j]+num[k];
				
				if(sum == target){
					return sum;
				}
				else if(sum < target){
					if(min > target-sum){
						min = target-sum;
						retval = sum;
					}
					j++;
				}
				else{
					if(sum-target < min){
						min = sum-target;
						retval = sum;
					}
					k--;
				}
					
			}
		}
		return retval;
    }
};

int main(){
	
	int a[] = {13,2,0,-14,-20,19,8,-5,-13,-3,20,15,20,5,13,14,-17,-7,12,-6,0,20,-19,-1,-15,-2,8,-2,-9,13,0,-3,-18,-9,-9,-19,17,-14,-19,-4,-16,2,0,9,5,-7,-4,20,18,9,0,12,-1,10,-17,-11,16,-13,-14,-3,0,2,-18,2,8,20,-15,3,-13,-12,-2,-19,11,11,-10,1,1,-10,-2,12,0,17,-19,-7,8,-19,-17,5,-5,-10,8,0,-12,4,19,2,0,12,14,-9,15,7,0,-16,-5,16,-12,0,2,-16,14,18,12,13,5,0,5,6};
	vector<int> vec(a,a+118);
	int  retval;	
	Solution s;
	retval = s.threeSumClosest(vec,-59);
	cout<<retval<<endl;
	return 0;
}
