#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int count = 0;
        int candidate = 0;
        
        for(int i=0;i<nums.size();i++){
            if(count == 0){
                candidate = nums[i];
            }
            count += nums[i] == candidate ? 1 : -1;
        }
        
        return candidate;
        
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
    cout<<solution->majorityElement(nums);
    
    return 0;
    
}
