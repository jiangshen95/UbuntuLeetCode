#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int, int> map;
        for(int i=0;i<nums.size();i++){
            if(map.find(nums[i])!=map.end()){
                map[nums[i]]++;
            }else{
                map[nums[i]] = 1;
            }
            
            if(map[nums[i]] > nums.size()/2) return nums[i];
        }
        
        return 0;
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
