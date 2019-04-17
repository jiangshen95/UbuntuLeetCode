#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<int> dp(nums.size());
        for(int i = nums.size() - 1; i >= 0; i--) {
        	for(int j = i; j < nums.size(); j++) {
        		if(i == j) dp[j] = nums[i];
        		else dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
			}
		}
		
		return dp[nums.size() - 1] >= 0;
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
	solution->PredictTheWinner(nums) ? cout<<"true" : cout<<"false";
	
	return 0;
}
