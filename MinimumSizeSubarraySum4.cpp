#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        
        int left = 0;
        int sum = 0;
        int minSub = -1;
        
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            while(sum >= s){
                if(minSub == -1 || minSub > (i - left + 1))
                    minSub = i - left + 1;
                sum -= nums[left++];
            }
        }
        
        return minSub == -1 ? 0 : minSub;
        
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
    
    int s;
    cin>>s;
    
    Solution *solution = new Solution();
    cout<<solution->minSubArrayLen(s, nums);
    
    return 0;
    
}
