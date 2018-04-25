#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        /*
         * 暴力搜索 改进
         */
        if(nums.empty()) return 0;
        
        int minSub = -1;
        vector<int> sums(nums.size());
        sums[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            sums[i] = sums[i-1] + nums[i];
        }
        
        for(int i=0;i<nums.size();i++){
            for(int j=i;j<nums.size();j++){
                int sum = sums[j] - sums[i] + nums[i];
                if(sum >= s){
                    if(minSub == -1 || (j - i + 1) < minSub) minSub = j - i + 1;
                }
            }
        }
        
        
        return minSub == -1 ? 0 : minSub;
        
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
    
    int s;
    cin>>s;
    
    Solution *solution = new Solution();
    cout<<solution->minSubArrayLen(s, nums);
    
    return 0;
    
}
