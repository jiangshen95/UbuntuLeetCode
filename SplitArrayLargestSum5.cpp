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
        	
        for(int i = 0; i < n; i++) dp[i] = sums[i + 1];
        
        for(int i = 1; i < m; i++) {
        	for(int j = n - 1; j >= i; j--) {
        		dp[j] = INT_MAX;
        		for(int k = j - 1; k >= i - 1; k--) {
        			int t = max(dp[k], sums[j + 1] - sums[k + 1]);
        			if(t <= dp[j]) dp[j] = t;
        			else break;
				}
			}
		}
        
        return dp[n - 1];
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
