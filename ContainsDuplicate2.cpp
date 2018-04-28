#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=1;i<nums.size();i++){
            if(nums[i] == nums[i-1]) return true;
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

