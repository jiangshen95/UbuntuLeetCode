#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
    	vector<int> dp(target + 1, 0);
    	dp[0] = 1;
    	for(int i = 1; i <= target; i++) {
    		for(int num : nums) {
    			if(i - num >= 0) dp[i] += dp[i - num];
			}
		}
		return dp.back();
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
