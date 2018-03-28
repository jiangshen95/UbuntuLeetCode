/*
 * 不符合空间O(1)，空间复杂度为O(k)
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        k %= n;
        
        nums.insert(nums.begin(), nums.end() - k, nums.end());
        nums.erase(nums.end() - k, nums.end());
        
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
    
    int k;
    cin>>k;
    
    Solution *solution = new Solution();
    solution->rotate(nums, k);
    
    for(int i=0;i<n;i++) cout<<nums[i]<<"  ";
    
    return 0;
    
}
