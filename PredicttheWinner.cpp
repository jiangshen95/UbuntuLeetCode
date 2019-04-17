#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        vector<vector<int> > dp(nums.size(), vector<int>(nums.size()));
        vector<vector<int> > sums(nums.size(), vector<int>(nums.size()));
        for(int i = nums.size() - 1; i >= 0; i--) {
        	for(int j = i; j < nums.size(); j++) {
        		if(i == j) {
        			dp[i][j] = nums[i];
        			sums[i][j] = nums[i];
				}
        		else {
        			sums[i][j] = sums[i][j - 1] + nums[j];
        			dp[i][j] = max(nums[i] + sums[i + 1][j] - dp[i + 1][j], nums[j] + sums[i][j - 1] - dp[i][j - 1]);
				}
				cout<<"i: "<<i<<"  j: "<<j<<"  dp: "<<dp[i][j]<<endl;
			}
		}
		
		return 2 * dp[0][nums.size() - 1] >= sums[0][nums.size() - 1];
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
