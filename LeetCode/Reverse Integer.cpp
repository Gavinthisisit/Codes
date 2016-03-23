#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
    	cout<<x<<endl;
    	long long tmp = x;
		long long retval = 0;
		while(tmp){
			retval = retval*10 + tmp%10;
			tmp /= 10;
		}
		
		if(retval > 2147483647 || (x<0 && retval > 2147483648))  {
             return 0;
        }
		return (int)retval;
		    
    }
};


int main(){
	Solution s;
	cout<<s.reverse(-2147483648);
	return 0;
}
