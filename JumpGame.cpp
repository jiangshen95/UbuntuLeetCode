/*
 * Time Limit Exceeded
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        if(nums.size()<2){
            return true;
        }
        return canJump(nums,0);
        
    }
    
    bool canJump(vector<int>& nums,int l){
        int n=nums[l];
        for(int i=n;i>0;i--){
            if(l+i>=nums.size()-1){
                return true;
            }
            if(canJump(nums,l+i)){
                return true;
            }
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
    
    Solution *solution=new Solution();
    solution->canJump(nums) ? cout<<"True" : cout<<"False";
    
    return 0;
    
}
