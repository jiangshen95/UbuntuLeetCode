#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        int res=nums[0], dp_min = nums[0], dp_max = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]>=0){
                dp_min *= nums[i];
                dp_max = max(dp_max*nums[i], nums[i]);
            }else if(nums[i]<0){
                int before = dp_min;
                dp_min = min(dp_max*nums[i], nums[i]);
                dp_max = max(before*nums[i], nums[i]);
            }
            
            cout<<"dp_min: "<<dp_min<<endl;
            cout<<"dp_max: "<<dp_max<<endl;
            
            res = max(dp_max, res);
        }
        
        return res;
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
    cout<<solution->maxProduct(nums);
    
    return 0;
}
