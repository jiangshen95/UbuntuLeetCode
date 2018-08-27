/**
* Wran Answer
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        if(amount == 0) return 0;
        sort(coins.begin(), coins.end());
        return coinChange(coins, coins.size() - 1, amount);
        
    }
    
    int coinChange(vector<int> coins, int begin, int value) {
    	
    	for(int i = begin; i >= 0; i--) {
    		cout<<coins[i]<<"  "<<value<<endl;
    		if(value > coins[i]) {
    			int temp = coinChange(coins, i, value - coins[i]);
    			if(temp > 0) {
    				return temp + 1;
				}
			}else if(value == coins[i]) {
				return 1;
			}
    		
		}
		
		return -1;
    	
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
