#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
    	map<long,int> m;
    	m.insert(pair<int,int>(n,1));
    	long p = n;
    	while(p!=1){
    		p = sum(p);
    		if(m.find(p)!= m.end())
    			return false;
    		else
    			m.insert(pair<int,int>(p,1));
    	}
    	return true;
    	    
    }
    long sum(long t){
    	vector<int> vec;
    	int tmp = t;
    	while(tmp){
    		int p = tmp%10;
    		tmp = tmp/10;
    		vec.push_back(p);
    	}
    	long retval = 0;
    	for(int i=0;i<vec.size();i++)
    		retval += vec[i]*vec[i];
    	return retval;
    }
};


int main(){
	Solution s;
	cout<<s.isHappy(19);
	return 0;
} 
