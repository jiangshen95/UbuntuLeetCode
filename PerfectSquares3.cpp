#include<iostream>
#include<math.h>
#include<algorithm> 
#include<vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        
        for(int i=0;i<=n;i++) {
        	for(int j=1;i+j*j<=n;j++) {
        		dp[i + j * j] = min(dp[i] + 1, dp[i + j * j]);
			}
		}
        
        return dp.back();
    }
    
};

int main() {
	
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->numSquares(n);
	
	return 0;
	
}
