#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	/*
	* dynamic programming
	*/
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        vector<vector<int> > dp(m + 1, vector<int>(n + 1, INT_MAX));
        vector<int> sums(n + 1, 0);
        for(int i = 0; i < n; i++)
        	sums[i + 1] = sums[i] + nums[i];
        
        dp[0][0] = 0;
        for(int i = 1; i <= m; i++) {
        	for(int j = i; j <= n; j++) {
        		for(int k = i - 1; k < j; k++) {
        			dp[i][j] = min(dp[i][j], max(dp[i - 1][k], sums[j] - sums[k]));
				}
			}
		}
		
		return dp[m][n];
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
	
	int m;
	cin>>m;
	
	Solution *solution = new Solution();
	cout<<solution->splitArray(nums, m);
	
	return 0;
	
}
