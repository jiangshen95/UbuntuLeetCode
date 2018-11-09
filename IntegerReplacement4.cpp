#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int integerReplacement(int n) {
        vector<int> dp(n + 1, 0);
        for(int i = 2; i <= n; i++) {
        	if(i % 2 == 0) dp[i] = dp[i / 2] + 1;
        	else dp[i] = min(dp[i - 1], 1 + dp[i / 2 + 1]) + 1;
		}
		return dp.back();
    }
};

int main() {
	
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->integerReplacement(n);
	
	return 0;
	
}
