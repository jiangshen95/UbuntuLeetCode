#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        vector<int> dp(amount + 1, -1);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++) {
        	for(int j = 0; j <coins.size(); j++) {
        		if(i - coins[j] >= 0) {
        			if(dp[i - coins[j]] != -1) {
        				if(dp[i] == -1) dp[i] = dp[i - coins[j]] + 1;
        				else dp[i] = min(dp[i], dp[i - coins[j]] + 1);
					}
				}
			}
		}
		
		return dp[amount];
        
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
