#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target) return true;
            else if(nums[mid]==nums[l]&&nums[mid]==nums[r]){
                r--;
                l++;
            }
            else if(nums[mid]>=nums[l]&&nums[mid]>nums[r]){
                if(nums[mid]>target&&nums[l]<=target){
                    r=mid-1;
                }else{
                    l=mid+1;
                }
            }else{
                if(nums[mid]<=target&&nums[r]>=target){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            
            cout<<"l: "<<l<<endl;
            cout<<"r: "<<r<<endl;
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
    
    int target;
    cin>>target;
    
    Solution *solution=new Solution();
    solution->search(nums, target) ? cout<<"True" : cout<<"False";
    
    return 0;
}
