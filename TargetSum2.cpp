#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
    	int n = nums.size();
    	vector<unordered_map<int, int> > dp(n + 1);
    	dp[0][0] = 1;
    	for(int i = 0; i < n; i++) {
    		for(auto &a : dp[i]) {
    			int sum = a.first, count = a.second;
    			dp[i + 1][sum - nums[i]] += count;
    			dp[i + 1][sum + nums[i]] += count;
			}
		}
		return dp[n][S];
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
