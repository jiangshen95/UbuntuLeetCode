#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0, right = nums.size()-1;
        while(left<right){
            int mid = (left+right)/2;
            if(nums[mid]<nums[mid+1]) left = mid+1;
            else right = mid;
        }
        return nums[left];
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
