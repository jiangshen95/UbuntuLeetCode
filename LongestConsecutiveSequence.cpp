#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        int result = 0;
        for(int i=0;i<nums.size();i++) set.insert(nums[i]);
        for(int i=0;i<nums.size();i++){
            if(set.count(nums[i])>0){
                set.erase(nums[i]);
                int pre=nums[i]-1;
                while(set.count(pre)>0){
                    set.erase(pre);
                    pre--;
                }
                int next=nums[i]+1;
                while(set.count(next)>0){
                    set.erase(next);
                    next++;
                }
                if(next-pre-1>result) result=next-pre-1;
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
    
    Solution solution=Solution();
    cout<<solution.longestConsecutive(nums);
    
    return 0;
}
