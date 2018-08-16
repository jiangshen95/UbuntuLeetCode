#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
    	
    	int n = nums.size();
    	if(n == 0) return 0;
    	
    	vector<vector<int> > dp(n, vector<int>(n));
    	
    	for(int i = n - 1; i >= 0; i--) {
    		for(int j = i; j < n; j++) {
    			for(int k = i; k <= j; k++) {
    				dp[i][j] = max(dp[i][j], (k - 1 >= 0 ? dp[i][k - 1] : 0) + (k + 1 < n ? dp[k + 1][j] : 0) + nums[k] * (i - 1 >= 0? nums[i - 1] : 1) * (j + 1 < n ? nums[j + 1] : 1));
				}
			}
		}
        
        return dp[0][n - 1];
    }
};

int main() {
	
	int n;
	cin>>n;
	
	vector<int> nums;
	for(int i = 0; i < n; i++) {
		int num;
		cin>>num;
		nums.push_back(num);
	}
	
	Solution *solution = new Solution();
	cout<<solution->maxCoins(nums);
	
	return 0;
	
}
