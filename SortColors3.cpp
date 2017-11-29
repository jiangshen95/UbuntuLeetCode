#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int l=0, r=0;
        for(int i=0;i<nums.size();i++){
            int v=nums[i];
            nums[i]=2;
            if(v<2){
                nums[r]=1;
                r++;
            }
            if(v==0){
                nums[l++]=0;
            }
        }
        
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
    solution->sortColors(nums);
    
    for(int i=0;i<n;i++) cout<<nums[i]<<" ";
    
    return 0;
}

