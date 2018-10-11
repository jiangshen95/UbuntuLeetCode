#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0));
        
        for(int i = 2; i <= n; i++) {
        	
        	for(int j = i - 1; j > 0; j--) {
        		
        		int min_cost = INT_MAX;
        		for(int k = j + 1; k < i; k++) {
        			min_cost = min(min_cost, k + max(dp[j][k - 1], dp[k + 1][i]));
				}
				
				dp[j][i] = j + 1 == i ? j : min_cost;
        		
			}
		}
		
		return dp[1][n];
    }
};

int main() {
	
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->getMoneyAmount(n);
	
	return 0;
	
} 
