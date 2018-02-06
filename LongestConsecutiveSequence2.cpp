#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> map;
        int result = 0;
        for(int i=0;i<nums.size();i++){
            if(map.count(nums[i])==0){
                int left = map.count(nums[i]-1)?map[nums[i]-1]:0;
                int right = map.count(nums[i]+1)?map[nums[i]+1]:0;
                int sum=left+right+1;
                map[nums[i]]=sum;
                if(sum>result) result=sum;
                map[nums[i]-left]=sum;
                map[nums[i]+right]=sum;
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
