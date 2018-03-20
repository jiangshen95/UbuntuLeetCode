#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0) return 0;
        
        int res=nums[0], dp_min = nums[0], dp_max = nums[0];
        for(int i=1;i<nums.size();i++){
            /*if(nums[i]<0) swap(dp_min, dp_max);
            
            dp_max = max(nums[i], dp_max*nums[i]);
            dp_min = min(nums[i], dp_min*nums[i]);*/
            int temp = dp_max;
            dp_max = max(max(nums[i]*dp_max, nums[i]*dp_min), nums[i]);
            dp_min = min(min(nums[i]*temp, nums[i]*dp_min), nums[i]);
            
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
