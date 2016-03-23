#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution
{
 public:
	 vector<int> twoSum(vector<int> &numbers,int target)
	 {
		int i;
		map<int,int> hmap;
		vector<int> retval;
		int n = 0;
		for(i=0;i<numbers.size();i++){
			if(!hmap.count(numbers[i])){
				hmap.insert(pair<int,int>(numbers[i],i));
			}
			if(hmap.count(target-numbers[i])){
				 n = hmap[target-numbers[i]];
				if(n<i){
					retval.push_back(n+1);
					retval.push_back(i+1);
				}
			}
		}
	
		return retval;
	 }
};



int main(){
	
	int a[] = {2, 7, 11, 15};
	vector<int> vec(a,a+4);
	Solution s;
	vector<int> ret;
	ret = s.twoSum(vec,9);
	int i = 0;
	while(i<ret.size()){
		cout<<ret[i]<<" ";
		i++;
	}
	cout<<endl;
	return 0;
}

 
