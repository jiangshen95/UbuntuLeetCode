#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int>  map;
        /*for(int i=0;i<nums.size();i++){
            if(map[nums[i]]) return true;
            map[nums[i]] ++;
        }*/
        for(auto num : nums){
            if(map[num]) return true;
            map[num] ++;
        }
        return false;
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
    solution->containsDuplicate(nums) ? cout<<"True" : cout<<"False";
    
    return 0;
    
}
