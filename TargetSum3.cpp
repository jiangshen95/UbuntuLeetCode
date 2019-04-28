#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
    	int n = nums.size();
    	unordered_map<int, int> dp;
    	dp[0] = 1;
    	for(int i = 0; i < n; i++) {
    		unordered_map<int, int> t;
    		for(auto &a : dp) {
    			int sum = a.first, count = a.second;
    			t[sum - nums[i]] += count;
    			t[sum + nums[i]] += count;
			}
			dp = t;
		}
		return dp[S];
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
