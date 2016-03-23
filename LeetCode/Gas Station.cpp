#include <iostream>
#include <vector>

using namespace std;


//之前的本办法
/* 
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		if(gas.size()==0)
			return -1;
        int i;
        vector<int> sub;
        sub_gas_cost(sub,gas,cost);
        int t = check_max(sub);
        bool flag = dfs(sub,t,0,0);
    
        if(!flag)
        	return -1;
        else
        	return t;
    }
    bool dfs(vector<int>& sub,int pos,int gasremain,int count){
    	if(count == sub.size())
    		return true;
    	int t = gasremain+sub[pos%sub.size()];
    	if(t < 0)
    		return false;
    	return dfs(sub,pos+1,t,count+1);
    }
    void sub_gas_cost(vector<int>& sub,vector<int>& gas,vector<int>& cost){
    	int n = gas.size();
    	for(int i=0;i<n;i++){
    		int tmp = gas[i]-cost[i];
    		sub.push_back(tmp);	
    	}
    }
    int check_max(vector<int>& sub){
		int i = 0;
		int pos = 0;
		int max = -65535;
		int count = 0;
		int p = 0;
		while(i<sub.size()){
			count += sub[i];
			if(max < count){
				max = count;
				p = i;
			}
			else if(max == count){
				if(sub[p] < sub[i])
					p = i;
			}
			i++;		
		}
		count = max;
		max = 0;
		i = 0;
 		while(i<p){
			count = count-sub[i];
			if(count > max){
				max = count;
				pos = i+1;
			}
			i++;		
		}
    	return pos;
    }
};
*/

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int pos = 0;
		int stationcount = 1;
		int gasremain = 0;
		for(int i=0;i<gas.size();i++){
			gasremain = gasremain+gas[i]-cost[i];
			
			if(gasremain < 0){
				gasremain = 0;
				pos = i+1;
			}
		} 
		 if(pos >= gas.size())
		 	return -1;
		 	
		int res = pos;
		
		while(stationcount <= gas.size() && gasremain >= 0){
			gasremain = gasremain + gas[pos] - cost[pos];
			
			pos = (pos+1)%gas.size();
			
			stationcount++;
		}
		if(gasremain < 0)
			return -1;
		else
			return res;
    }
};

int main(){
	int a[] = {99,98,97,100};
	int b[] = {100,100,100,97};
//	int c[] = {-22,1,-4,1,2,3,-1,20};
	
	vector<int> gas(a,a+5);
	vector<int> cost(b,b+5);
//	vector<int> v(c,c+8);
	
	Solution s;
	cout<<s.canCompleteCircuit(gas,cost)<<endl;

	
	return 0;
}
