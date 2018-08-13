#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	
    	int n = prices.size();
    	if(n == 0) return 0;
    	
    	int sell = 0, rest = 0;
    	for(int i = 1; i < n; i++) {
    		int temp = sell;
    		sell = max(sell + prices[i] - prices[i - 1], rest);
    		rest = max(temp, rest);
		}
		
		return max(rest, sell);
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
