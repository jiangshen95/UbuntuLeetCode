#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int rob1 = rob(nums, 0, nums.size() - 2);
        int rob2 = rob(nums, 1, nums.size() - 1);
        
        return max(rob1, rob2);
    }
    
    int rob(vector<int>& nums, int begin, int end){
        int pre = 0;
        int cur = 0;
        for(int i=begin;i<=end;i++){
            int temp = cur;
            cur = max(pre + nums[i], cur);
            pre = temp;
        }
        
        return cur;
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
