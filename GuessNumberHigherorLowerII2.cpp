#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int> > dp(n + 1, vector<int>(n + 1, 0));
        
        return help(1, n, dp);
    }
    
    int help(int start, int end, vector<vector<int> >& dp) {
    	if(start >= end) return 0;
    	if(start + 1 == end) return start;
    	if(dp[start][end] > 0) return dp[start][end];
    	
    	int min_cost = INT_MAX;
    	for(int k = start; k <= end; k++) {
    		min_cost = min(min_cost, k + max(help(start, k - 1, dp), help(k + 1, end, dp)));
		}
		dp[start][end] = min_cost;
		
		return min_cost;
	}
};

int main() {
	
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->getMoneyAmount(n);
	
	return 0;
	
} 
