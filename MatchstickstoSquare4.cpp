/*
 * Time Limit Exceeded
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size() <= 3) return false;
        int sum = 0;
        for(int num : nums) sum += num;
        if(sum % 4) return false;
        int len = sum / 4;
        int n = nums.size();
        int all = (1 << n) - 1;
        vector<int> masks;
        dfs(nums, masks, 0, 0, len);
        vector<bool> dp(1 << n, false);
        dp[0] = true;
        for(int mask : masks) {
        	for(int i = all; i >= 0; i--) {
        		if(dp[i] && (mask & i) == 0) {
        			dp[i | mask] = true;
				}
			}
		}
		
		return dp.back();
    }
    
    void dfs(vector<int>& nums, vector<int>& masks, int mask, int pos, int len) {
    	if(len == 0) {
    		cout<<mask<<endl;
    		masks.push_back(mask);
    		return;
		}
		if(pos >= nums.size()) return;
    	
    	if(nums[pos] <= len) dfs(nums, masks, mask | (1 << pos), pos + 1, len - nums[pos]);
    	
    	dfs(nums, masks, mask, pos + 1, len);
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
	solution->makesquare(nums) ? cout<<"true" : cout<<"false";
	
	return 0;
}
