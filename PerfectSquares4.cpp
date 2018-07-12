#include<iostream>
#include<math.h>
#include<algorithm> 
#include<vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        
        vector<int> dp(1, 0);
        
        for(int i = 1;i<=n;i++) {
        	int val = INT_MAX;
        	for(int j=1;j*j<=i;j++) {
        		val = min(val, dp[i - j * j] + 1);
			}
			dp.push_back(val);
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
