#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int a = 0;
        int b = 0;
        
        for(int i=0;i<nums.size();i++){
            if(i%2 == 0){
                a = max(a+nums[i], b);
            }else{
                b = max(b+nums[i], a);
            }
        }
        
        return max(a, b);
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
