#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left=0, right=nums.size()-1;
        
        while(left<right){
            int mid = (left+right)/2;
            if(nums[mid]>nums[right]){
                left = mid+1;
            }else if(nums[mid]<nums[right]){
                right = mid;
            }else{
                //right--;
                /*
                 * an other solution
                 */
                if(nums[left]==nums[mid]){
                    left++;
                    right--;
                }else{
                    right = mid;
                }
            }
        }
        
        return nums[left];
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
