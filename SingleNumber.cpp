/*
 * Time Limit Exceeded
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(int i=0;i<nums.size();i+=2){
            int j;
            for(j=i+1;j<nums.size();j++){
                if(nums[i]==nums[j]){
                    int t=nums[i+1];
                    nums[i+1]=nums[j];
                    nums[j]=t;
                    break;
                }
            }
            if(j==nums.size()) return nums[i];
        }
        return 0;
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
    cout<<solution->singleNumber(nums);
    
    return 0;
}
