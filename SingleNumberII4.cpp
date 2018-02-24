#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x1=0, x2=0, mask=0;
        for(int i=0;i<nums.size();i++){
            x2 ^= x1&nums[i];
            x1 ^= nums[i];
            mask = ~(x1&x2);
            x2 &= mask;
            x1 &= mask;
        }
        return x1;
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
