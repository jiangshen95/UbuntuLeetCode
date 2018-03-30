#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int local = 0;
        int pre = 0;
        
        for(int i=0;i<nums.size();i++){
            int temp = local;
            local = max(local, pre + nums[i]);
            pre = temp;
            cout<<"nums[i]: "<<nums[i]<<endl;
            cout<<"local: "<<local<<endl;
            cout<<"pre: "<<pre<<endl;
        }
        
        return local;
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
    cout<<solution->rob(nums);
    
    return 0;
    
}
