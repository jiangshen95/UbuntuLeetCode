#include<iostream>
#include<vector>
#include<math.h>
#include<unordered_map>
#include<limits.h>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k < 1 || t < 0) return false;
        unordered_map<long, long> map;
        for(int i=0;i<nums.size();i++){
            if(i > k){
                map.erase((long(nums[i - k - 1]) - INT_MIN) / ((long)t + 1));
            }
            long remapednum = (long)nums[i] - INT_MIN;
            long bucket = remapednum / ((long)t + 1);
            if(map.find(bucket) != map.end() || (map.find(bucket - 1) != map.end() && remapednum - map[bucket - 1] <= t) ||
               (map.find(bucket + 1) != map.end() && map[bucket + 1] - remapednum <= t)) return true;
            map[bucket] = remapednum;
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
