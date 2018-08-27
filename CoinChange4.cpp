#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        if(amount == 0) return 0;
        
        vector<bool> visited(amount + 1, false);
        vector<int> value1(1, 0);
        int nc = 0;
        visited[0] = true;
        
        while(!value1.empty()) {
        	vector<int> value2;
        	nc++;
        	for(int i = 0; i < value1.size(); i++) {
        		for(int j = 0; j < coins.size(); j++) {
        			int temp = value1[i] + coins[j];
        			if(temp == amount) return nc;
        			if(temp < amount && !visited[temp]) {
        				value2.push_back(temp);
        				visited[temp] = true;
					}
				}
			}
			value1 = value2;
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
