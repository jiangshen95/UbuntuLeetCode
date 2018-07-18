#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	
    	int n = nums.size();
    	int result = 0;
    	
    	vector<int> dp(n, 1);
    	
    	for(int i=0;i<nums.size();i++) {
    		for(int j=0;j<i;j++) {
    			if(nums[i] > nums[j]) {
    				dp[i] = max(dp[i], 1 + dp[j]);
				}
			}
			result = max(result, dp[i]);
		}
		
		return result;
        
    }
    
};

int main() {
	
	int n;
	cin>>n;
	
	vector<int> nums;
	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		nums.push_back(num);
	} 
	
	Solution *solution = new Solution();
	cout<<solution->lengthOfLIS(nums);
	
	return 0;
	
}
