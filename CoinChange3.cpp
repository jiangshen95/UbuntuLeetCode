#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        unordered_map<int, int> dp;
        dp[0] = 0;
        return coinChange(coins, dp, amount);
        
    }
    
    int coinChange(vector<int> coins, unordered_map<int, int>& dp, int amount) {
    	
    	if(amount == 0) return 0;
    	if(dp.find(amount) != dp.end()) return dp[amount];
    	
    	int cur = INT_MAX;
    	for(int coin : coins) {
    		if(amount >= coin) {
    			int temp = coinChange(coins, dp, amount - coin);
    			if(temp >= 0) {
    				cur = min(cur, temp + 1);
				}
			}
		}
		
		return dp[amount] = cur == INT_MAX ? -1 : cur;
		
    	
	}
    
};

int main() {
	
	int n;
	cin>>n;
	
	vector<int> coins;
	for(int i = 0; i < n; i++) {
		int coin;
		cin>>coin;
		coins.push_back(coin);
	}
	int amount;
	cin>>amount;
	
	Solution *solution = new Solution();
	cout<<solution->coinChange(coins, amount);
	
	return 0;
	
}
