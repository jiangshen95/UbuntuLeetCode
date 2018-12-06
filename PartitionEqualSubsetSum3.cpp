#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum = 0;
        for(int num : nums) sum += num;
        
        if(sum % 2) return false;
        
        sum /= 2;
        
        int n = nums.size();
        
        vector<vector<bool> > dp(n, vector<bool>(sum + 1, false));
        for(int i = 0; i < n; i++) dp[i][0] = true;
        
        for(int i = 0; i < n; i++) {
        	if(i == 0) {
        		dp[i][nums[i]] = true;
        		continue;
			}
        	for(int j = nums[i]; j <= sum; j++) {
        		dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i]];
			}
		}
		
		return dp[n - 1][sum];
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
	solution->canPartition(nums) ? cout<<"true" : cout<<"false";
	
	return 0;
	
}
