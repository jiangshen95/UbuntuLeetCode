#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        
        int competitor1 = 0, count1 = 0;
        int competitor2 = 0, count2 = 0;
        
        for(int i=0;i<n;i++){
            if(count1 == 0 &&(count2 == 0 ||(count2 != 0 && competitor2 != nums[i]))) {
                competitor1 = nums[i];
                count1 ++;
                continue;
            }
            if(count2 == 0 && nums[i] != competitor1){
                competitor2 = nums[i];
                count2 ++;
                continue;
            }
            if(nums[i] == competitor1) count1 ++;
            else if(nums[i] == competitor2) count2 ++;
            else{
                count2 --;
                count1 --;
            }
        }
        
        vector<int> result;
        count1 = 0;
        count2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == competitor1) count1 ++;
            else if(nums[i] == competitor2) count2 ++;
        }
        if(count1 > n / 3) result.push_back(competitor1);
        if(count2 > n / 3) result.push_back(competitor2);
        
        return result;
    }
};

int main() {
    
    int n;
    cin>>n;
    
    vector<int> nums;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        nums.push_back(num);
    }
    
    Solution *solution = new Solution();
    vector<int> result = solution->majorityElement(nums);
    for(int i=0;i<result.size();i++) cout<<result[i]<<"  ";
    
    return 0;
    
}
