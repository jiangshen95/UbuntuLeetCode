/*
 * 原始的动态规划算法，写一下，别看不懂前面的了。。。
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.empty()) return 0;
        vector<int> dp(nums.size());
        
        for(int i=0;i<nums.size();i++){
            if(i == 0) dp[i] = nums[0];
            else if(i == 1) dp[i] = max(nums[0], nums[1]);
            else dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
        }
        
        return dp.back();
    }
};

int main(){
    
    int n;
    cin>>n;
    
    vector<int> nums;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums.push_back(num);
    }
    
    Solution *solution = new Solution();
    cout<<solution->rob(nums);
    
    return 0;
    
}
