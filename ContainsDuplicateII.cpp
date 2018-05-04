#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for(int i=0;i<nums.size();i++){
            if(map.find(nums[i]) == map.end()){
                map[nums[i]] = i;
            }else{
                if(i - map[nums[i]] <= k) return true;
                map[nums[i]] = i;
            }
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
    
    int k;
    cin>>k;
    
    Solution *solution = new Solution();
    solution->containsNearbyDuplicate(nums, k) ? cout<<"True" : cout<<"False";
    
    return 0;
    
}
