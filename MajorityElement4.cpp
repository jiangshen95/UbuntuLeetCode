#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int result = 0;
        
        for(int i=0;i<32;i++){
            
            int count = 0;
            for(int j=0;j<nums.size();j++){
                if((nums[j]&(1<<i)) != 0){
                    count++;
                }
            }
            
            if(count > nums.size()/2){
                result |= 1<<i;
            }
            
        }
        
        return result;
        
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
