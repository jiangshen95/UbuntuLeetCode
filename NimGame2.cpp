#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
    	
    	if(n < 4) return true;
        
        vector<bool> dp(n + 1);
        dp[0] = true;
        dp[1] = true;
        dp[2] = true;
        dp[3] = true;
        
        for(int i=4;i<=n;i++) {
        	dp[i] = !(dp[i - 1] && dp[i - 2] && dp[i - 3]);
		}
		
		return dp[n];
        
    }
};

int main() {
	int n;
	cin>>n;
	Solution *solution = new Solution();
	solution->canWinNim(n) ? cout<<"true" : cout<<"false";
	
	return 0;
}
