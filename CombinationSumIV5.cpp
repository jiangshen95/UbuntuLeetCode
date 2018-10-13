#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
    	vector<int> dp(target + 1, -1);
    	dp[0] = 1;
    	return helper(dp, nums, target);
    }
    
    int helper(vector<int>& dp, vector<int>& nums, int target) {
    	if(target < 0) return 0;
    	if(dp[target] != -1) return dp[target];
    	int count = 0;
    	for(int num : nums) {
    		if(target >= num) count += helper(dp, nums, target - num);
		}
		dp[target] = count;
		return count;
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
	
	int target;
	cin>>target;
	
	Solution *solution = new Solution();
	cout<<solution->combinationSum4(nums, target);
	
	return 0;
	
}
