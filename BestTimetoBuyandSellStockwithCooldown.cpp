/*
** Time Limit Exceeded
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	
    	return maxProfit(prices, 0);
    	
    }
    
    int maxProfit(vector<int> prices, int begin) {
    	int m = 0;
    	for(int i = begin + 1; i < prices.size(); i++) {
    		if(prices[i] > prices[i - 1]) {
    			m = max(m, prices[i] - prices[begin] + maxProfit(prices, i + 2));
			}else {
				m = max(m, maxProfit(prices, i));
			}
		}
		return m;
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
