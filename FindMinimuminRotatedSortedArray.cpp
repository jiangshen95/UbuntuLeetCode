#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int min = nums[0];
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                min = nums[i+1];
                break;
            }
        }
        
        return min;
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
    cout<<solution->findMin(nums);
    
    return 0;
}
