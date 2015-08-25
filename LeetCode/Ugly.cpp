#include <iostream>
#include <vector>

using  namespace std;

class Solution {
public:
    bool isUgly(int num) {
    	if(num==0)
			return false;
		while(num){
			if(num%2==0){
				num = num/2;
				continue;
			}
			else if(num%3==0){
				num = num/3;
				continue;
			}
			else if(num%5==0){
				num = num/5;
				continue;
			}
			else if(num==1)
				return true;
			return false;
		}
		return true;    
    }
};

int main(){
	Solution s;
	cout<<s.isUgly(14);
	return 0;
} 
