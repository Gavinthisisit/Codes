#include <iostream>


using namespace std;

class Solution {
public:
	int bulbSwitch(int n) {
		return (int)sqrt(n);
	}
};


int main(){
	Solution s;
	cout << s.bulbSwitch(1000000) << endl;
	return 0;
}