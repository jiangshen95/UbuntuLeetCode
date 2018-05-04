#include<iostream>
#include<vector>
#include<math.h>
#include<set>
#include<limits.h>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k < 1 || t < 0) return false;
        set<long> window;
        for(int i=0;i<nums.size();i++){
            if(i > k) window.erase(nums[i - k - 1]);
            auto pos = window.lower_bound((long)nums[i] - t); //nums[i] - t <= x -> x - nums[i] >= -t
            cout<<*pos<<endl;
            if(pos != window.end() && (long)*pos - nums[i] <= t) return true; // x - nums[i] <= t  ==>  t <= x - nums[i] <= t
            window.insert(nums[i]);
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
