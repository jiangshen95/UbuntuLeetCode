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
        
        vector<bool> dp(sum + 1);
        dp[0] = true;
        
        for(int num : nums) {
        	for(int i = sum; i >= num; i--) dp[i] = dp[i] | dp[i - num];
		}
		
		return dp[sum];
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
