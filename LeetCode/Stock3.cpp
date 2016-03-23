#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	int size = prices.size();
		if(size == 0)
			return 0;  
		vector<int> profit1(size);
		vector<int> profit2(size);
		
		int min_Buy = prices[0];
		for(int i=1;i<size;i++){
			min_Buy = std::min(min_Buy,prices[i]);
			profit1[i] = std::max(profit1[i-1],prices[i]-min_Buy);
		}
		
		int max_Sold = prices[size-1];
		profit2[size-1] = 0;
		for(int i=size-2;i>=0;i--){
			max_Sold = std::max(max_Sold,prices[i]);
			profit2[i] = std::max(profit2[i+1],max_Sold - prices[i]);
		}
		
		int max_profit = 0;
		for(int i=0;i<size;i++){
			max_profit = std::max(max_profit,profit1[i]+profit2[i]);
		}
		
		return max_profit;
    }
		
    
};

int main(){
	
	int a[] = {6,1,3,2,4,7};
	vector<int> vec(a,a+6);
	
	Solution s;
	
	cout<<s.maxProfit(vec)<<endl;
	
	return 0;
}
