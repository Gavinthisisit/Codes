#include <iostream>
#include <vector>
using namespace std;





int main(){
	int a[] = {1,9,3,5,3,5,-2};
	int b[2];
	Two_Sum(a,7,7,b);
	cout<<b[0]<<" "<<b[1]<<endl;
	return 0;
}
