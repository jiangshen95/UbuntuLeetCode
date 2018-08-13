#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	
    	int n = prices.size();
    	if(n == 0) return 0;
    	
    	int pre_buy = 0, pre_sell = 0, buy = INT_MIN, sell = 0;
		
		for(int i = 0; i < n; i++) {
			pre_buy = buy;
			buy = max(pre_sell - prices[i], pre_buy);
			pre_sell = sell;
			sell = max(pre_buy + prices[i], pre_sell);
		}
		
		return sell;
    }
    
};

int main() {
	
	int n;
	cin>>n;
	
	vector<int> prices;
	for(int i = 0; i < n; i++) {
		int price;
		cin>>price;
		prices.push_back(price);
	}
	
	Solution *solution = new Solution();
	cout<<solution->maxProfit(prices);
	
	return 0;
	
}
