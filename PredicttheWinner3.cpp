#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
    	vector<vector<int> > dp(nums.size(), vector<int>(nums.size(), -1));
        return canWin(nums, 0, nums.size() - 1, dp) >= 0;
    }
    
    int canWin(vector<int>& nums, int start, int end, vector<vector<int> >& dp) {
    	if(dp[start][end] == -1) {
    		dp[start][end] = start == end ? nums[start] : max(nums[start] - canWin(nums, start + 1, end, dp), nums[end] - canWin(nums, start, end - 1, dp));
		}
		return dp[start][end];
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
