#include <iostream>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
    	static uint32_t key = 0;
    	if(n==key)
			return key;
		uint32_t retval = 0;
		int index = 31;
		while(n>0){
			retval |= (n & 0x1) <<index;
			index--;
			n >>= 1;
		}
		return retval;    
    }
};

int main(){
	Solution s;
	cout<<s.reverseBits(43261596);
	return 0;
}
