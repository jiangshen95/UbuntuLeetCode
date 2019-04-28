#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
    	int n = nums.size();
    	int sum = 0;
    	for(int num : nums) sum += num;
    	return S > sum ? 0 : (S + sum) % 2 == 1 ? 0 : subsetSum(nums, (S + sum) >> 1);
    }
    
    int subsetSum(vector<int>& nums, int target) {
    	vector<int> dp(target + 1);
    	dp[0] = 1;
    	for(int num : nums) {
    		for(int j = target; j >= num; j--) dp[j] += dp[j - num];
		}
		return dp[target];
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
	
	int S;
	cin>>S;
	
	Solution *solution = new Solution();
	cout<<solution->findTargetSumWays(nums, S);
	
	return 0;
}
