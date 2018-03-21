#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]) return i;
        }
        return nums.size()-1;
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
    cout<<solution->findPeakElement(nums)<<endl;
    
    return 0;
}
