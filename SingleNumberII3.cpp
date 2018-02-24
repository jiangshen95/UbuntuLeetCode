#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<32;i++){
            int sum=0;
            for(int j=0;j<nums.size();j++){
                if((nums[j]>>i)&1){
                    sum++;
                    sum%=3;
                }
            }
            if(sum!=0){
                ans |= sum<<i;
            }
        }
        
        return ans;
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
