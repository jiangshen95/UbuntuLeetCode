/*
 * Time Limit Exceeded
 */
#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k >= nums.size() - 1) k = nums.size() - 1;
        if(k <= 0) return false;
        long diff;
        for(int i=0;i<nums.size();i++){
            for(int j=max(i-k, 0);j<i;j++){
                diff = abs((long)nums[i] - nums[j]);
                cout<<diff<<endl;
                if(abs((long)nums[i] - nums[j]) <= t) return true;
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
    
    int k, t;
    cin>>k>>t;
    
    Solution *solution = new Solution();
    solution->containsNearbyAlmostDuplicate(nums, k, t) ? cout<<"True" : cout<<"False";
    
    return 0;
    
}
