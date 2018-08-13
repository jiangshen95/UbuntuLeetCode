#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	
    	int n = prices.size();
    	if(n == 0) return 0;
    	
    	vector<int> sell(n), buy(n), rest(n);
		
		for(int i = 0; i < n; i++) {
			if(i == 0) buy[i] = -prices[i];
			else {
				buy[i] = max(rest[i - 1] - prices[i], buy[i - 1]);
				sell[i] = max(buy[i - 1] + prices[i], sell[i - 1]);
				rest[i] = max(sell[i - 1], rest[i - 1]);
			}
		}
		
		return max(sell[n - 1], rest[n - 1]);
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
