#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        if(nums.empty()) return 0;
        
        int l = 0, r = 0;
        int sum = nums.front();
        int minSub = -1;
        
        while(l < nums.size() && r < nums.size()) {
            if(sum >= s) {
                if(minSub == -1 || (r - l + 1) < minSub) minSub = r - l + 1;
                sum -= nums[l];
                l ++;
            }else {
                r ++;
                sum += nums[r];
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
