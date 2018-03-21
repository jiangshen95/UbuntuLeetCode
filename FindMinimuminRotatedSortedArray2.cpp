#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int begin=0, end=nums.size()-1;
        
        while(begin<end){
            if(nums[begin]<nums[end]) return nums[begin];
            
            int mid = (begin+end)/2;
            if(nums[mid]>=nums[begin]){
                begin = mid+1;
            }else{
                end = mid;
            }
        }
        
        return nums[begin];
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
    cout<<solution->findMin(nums);
    
    return 0;
}
