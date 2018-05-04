#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> set;
        for(int i=0;i<nums.size();i++){
            if(i > k) set.erase(nums[i - k - 1]);
            if(set.find(nums[i]) != set.end()) return true;
            set.insert(nums[i]);
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
