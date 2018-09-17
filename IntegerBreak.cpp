#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(1);
        for(int i = 2; i <= n; i++) {
        	int m = 0;
        	for(int j = 1; j < i; j++) {
        		m = max(m, max(dp[j], j) * (i - j));
			}
			dp.push_back(m);
		}
		
		return dp.back();
    }
};

int main() {
	
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->integerBreak(n);
	
	return 0;
	
}
