#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if(prices.size()<2)
    		return 0;
    	vector<int> trend;
    	vector<int> money;
		
		int i = 1;
		if(prices[0] < prices[1]){
			trend.push_back(-1);
			money.push_back(prices[0]);
		}
		int flag = 0;
		int isBuy;
		while(i<prices.size()-1){
			if(prices[i] >= prices[i-1] && prices[i] > prices[i+1]){
				trend.push_back(1);
				money.push_back(prices[i]);
				isBuy = 0;	
			}
			else if(prices[i] <= prices[i-1] && prices[i] < prices[i+1]){
				trend.push_back(-1);
				money.push_back(prices[i]);
				isBuy = 1;
			}
			i++;	
		}
		if(isBuy == 1){
			trend.push_back(1);
			money.push_back(prices[prices.size()-1]);
		}
		else if(prices[prices.size()-1] > prices[prices.size()-2]){
			trend.push_back(1);
			money.push_back(prices[prices.size()-1]);
		}
		
		return twoTimeMax(money,trend);
			 
/*		int pre_price;										//不限制购买次数 
		int has_Buy = 0;
		while(i<trend.size()){
			if(trend[i] == -1 && has_Buy == 0){
				profit = profit - prices[i];
				has_Buy = 1;
			}
			if(trend[i] == 1 && has_Buy == 1){
				profit = profit + prices[i];
				has_Buy = 0;
			}
			i++;
		}
		return profit;*/
    }
    int twoTimeMax(vector<int>& prices,vector<int>& trend){
    	int i = 0;
    	int max_profit = 0;
    	while(i<trend.size()){
    		if(trend[i] == -1){
    			int tmp = getMax(prices,trend,i);
    			if(tmp > max_profit)
    				max_profit = tmp;
    		}
    		i++;
    	}
    	return max_profit;
    } 
    int getProfit(vector<int>& prices,vector<int>& trend,int i,int n){
		int profit = 0;
		int max_profit = 0;
    	while(i<n){														//只许购买一次 
	    	if(trend[i] == -1){
	    		for(int j=i+1;j<n;j++){
	    			if(trend[j] == 1){
	    				profit = prices[j] - prices[i];
	    				if(max_profit < profit)
	    					max_profit = profit;
	    			}
	    		}
		    }
		    i++;
    	} 
    	return max_profit;
	}
	
	int getMax(vector<int>& prices,vector<int>& trend,int i){
		int j = 0;
		int max = 0;
		
		while(j<trend.size()){
			int tmp = getProfit(prices,trend,i,j)+getProfit(prices,trend,j,trend.size()); 
			if(tmp > max)
				max = tmp;
			j++;
		}
		return max;
		
	}
};


int main(){
	
	int a[] = {6,1,3,2,4,7};
	vector<int> vec(a,a+6);
	
	Solution s;
	
	cout<<s.maxProfit(vec)<<endl;
	return 0;
}
