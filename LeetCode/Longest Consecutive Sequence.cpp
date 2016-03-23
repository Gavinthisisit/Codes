#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        return mapCount(nums);
    }
    int mapCount(vector<int> &vec){
    	int i;
    	if(vec.size()<2)
    		return vec.size();
    	map<int,int> count_map;
    	map<int,int>::iterator itor;
    	for(i=0;i<vec.size();i++){
    		count_map.insert(pair<int,int>(vec[i],1));
    	}
    	int retval = 1;
    	int max = 1;
    	bool flag = 0;
    	i = 0;
    	for(itor=count_map.begin();itor!=count_map.end();++itor){
    		int t1 = itor->first;
			if(count_map.count(t1+1)>0){
				flag = 1;
				max += 1;
			}
			else if(flag){
				if(max>retval)
					retval = max;
				max = 1;
				flag = 0;
			}
			else
				max = 1;
    	}
    	return retval;
    }
};


int main(){
/*	map<int,int>  m;
    m[1]=1;
    m[-3]=2;
    m[2]=3;
    map<int,int>::iterator it;
    for(it=m.begin();it!=m.end();++it)
        cout<<"key: "<<it->first <<" value: "<<it->second<<endl;*/
    
    int a[] = {0,0};
    vector<int> vec(a,a+2);
    Solution s;

    cout<<s.longestConsecutive(vec)<<endl;
	return 0;
}
