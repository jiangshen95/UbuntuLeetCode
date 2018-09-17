#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp{0, 1, 1, 2, 4, 6, 9};
        for(int i = 7; i <= n; i++) {
        	dp.push_back(3 * dp[i - 3]);
		}
		
		return dp[n];
		
    }
};

int main() {
	
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->integerBreak(n);
	
	return 0;
	
}
