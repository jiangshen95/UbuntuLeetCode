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
        vector<int> dp(n);
        vector<int> sums(n + 1, 0);
        for(int i = 0; i < n; i++)
        	sums[i + 1] = sums[i] + nums[i];
        	
        for(int i = 0; i < n; i++) dp[i] = sums[n] - sums[i];
        
        for(int i = 1; i < m; i++) {
        	for(int j = 0; j < n - i; j++) {
        		dp[j] = INT_MAX;
        		for(int k = j + 1; k <= n - i; k++) {
        			int t = max(dp[k], sums[k] - sums[j]);
        			if(t <= dp[j]) dp[j] = t;
        			else break;
				}
			}
		}
        
        return dp[0];
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
