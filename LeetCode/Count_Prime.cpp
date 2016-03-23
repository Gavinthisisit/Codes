#include <iostream> 
#include <math.h>
#include <string.h>
using namespace std;

	class Solution {
	public:
	    int countPrimes(int n) {
	    	int count = 0;
			if(n<2)
				return count;
			bool prime[n];
			memset(prime,true,n*sizeof(bool));
			prime[0] = false;
			prime[1] = false;
			
			int t = sqrt(n);
			int i=2;
			while(i<=t){
				if(prime[i]){
					for(int j=i*i;j<n;j+=i){
						prime[j] = false;
					}
				}
				i++;
			}   
			for(i=0;i<n;i++)
				if(prime[i])
					count++; 
			return count;
	    }
	};

int main(){
	Solution s;
	cout<<s.countPrimes(5);
	return 0;
}
