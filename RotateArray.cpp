/*
 * Time Limit Exceeded
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int n = nums.size();
        
        for(int t=0;t<k%n;t++){
            
            int v = nums[n-1];
            
            for(int i = n-1;i>0;i--){
                nums[i] = nums[i-1];
            }
            
            nums[0] = v;
            
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
