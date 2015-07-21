#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
		vector<vector<int> >  retval;
		if(!n)
			return retval;
		int count = n/2+n%2;
		for(int i=0;i<n;i++){
			vector<int> tmp;
			for(int j=0;j<n;j++)
				tmp.push_back(0);
			retval.push_back(tmp);
		}
		int p = 0;
		int cir = n;
		int val = 1;
		while(p<count){
			creatCircle(retval,p,p,cir,val);
			val = val + 4*cir-4;
			cir -= 2;
			p++;	
		}
		return retval;
						     
    }
    void creatCircle(vector<vector<int> >& ret,int x,int y,int n,int val){
    	int i = 0;
    	if(n==1){
    		ret[x][y] = val;
    		return;
    	}
    		
		while(i<n-1){
			ret[x][y+i] = val;
			ret[x+i][y+n-1] = val+n-1;
			ret[x+n-1][y+n-1-i] = val+2*n-2;
			ret[x+n-1-i][y] = val+3*n-3;
			val++;
			i++; 
		}
    }
};



int main(){
	Solution s;
	vector<vector<int> > ret;
	ret = s.generateMatrix(5);
	for(int i=0;i<ret.size();i++){
		for(int j=0;j<ret[i].size();j++)
			cout<<ret[i][j]<<" ";
		cout<<endl;
	}
		
	return 0;
} 
