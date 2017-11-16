#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        bool is_can=true;
        int longest=nums[0];
        for(int i=1;i<nums.size();i++){
            cout<<"i: "<<i<<endl;
            cout<<"longest: "<<longest<<endl;
            if((is_can&&nums[i-1]>0)||longest>=i){
                is_can=true;
            }else{
                is_can=false;
                break;
            }
            
            if(is_can&&longest-i<nums[i]){
                longest=nums[i]+i;
            }
        }
        
        return is_can;
        
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

