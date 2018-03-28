#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        k = k%n;
        
        reverse(nums, 0, n-1);
        
        reverse(nums, 0, k-1);
        reverse(nums, k, n-1);
        
    }
    
    void reverse(vector<int>& nums, int l, int r){
        for(;l<r;l++, r--){
            int v = nums[l];
            nums[l] = nums[r];
            nums[r] = v;
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
    
    int k;
    cin>>k;
    
    Solution *solution = new Solution();
    solution->rotate(nums, k);
    
    for(int i=0;i<n;i++) cout<<nums[i]<<"  ";
    
    return 0;
    
}
