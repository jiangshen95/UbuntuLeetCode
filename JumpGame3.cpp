#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int lastposition=nums.size()-1;
        for(int i=nums.size()-1;i>=0;i--){
            if(i+nums[i]>=lastposition){
                lastposition=i;
            }
        }
        
        return lastposition==0;
        
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
