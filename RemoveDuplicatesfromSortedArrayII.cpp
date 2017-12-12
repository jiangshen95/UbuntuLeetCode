#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int curr=0;
        for(int i=0;i<nums.size();i++){
            if(curr<2||nums[i]>nums[curr-2]){
                nums[curr++]=nums[i];
            }
        }
        
        return curr;
        
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
    cout<<solution->removeDuplicates(nums);
    
    return 0;
}
