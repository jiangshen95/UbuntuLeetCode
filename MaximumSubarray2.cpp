/*
 * Divide and Conquer Approach 分治法
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        return helper(nums,0,nums.size()-1);
        
    }
    
    int helper(vector<int>& nums,int left,int right){
        
        if(left>=right) return nums[left];
        
        int mid=(left+right)/2;
        
        int lmax=helper(nums,left,mid-1);
        int rmax=helper(nums,mid+1,right);
        
        int sum=nums[mid];
        int t=nums[mid];
        
        for(int i=mid+1;i<=right;i++){
            t+=nums[i];
            sum=sum>t ? sum : t;
        }
        t=sum;
        for(int i=mid-1;i>=left;i--){
            t+=nums[i];
            sum=sum>t ? sum : t;
        }
        
        return (lmax>rmax ? lmax : rmax)>sum ? (lmax>rmax ? lmax : rmax) : sum;
        
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
    
    Solution *solution=new Solution();
    cout<<solution->maxSubArray(nums);
    
    return 0;
    
}
