#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        qsort(nums, 0, nums.size()-1);
        
        return nums[nums.size()/2];
    }
    
    void qsort(vector<int> &nums, int l, int r){
        if(l<r){
            int i = l, j = r;
            int v = nums[i];
            while(i<j){
                while(i<j&&nums[j]>=v) j--;
                nums[i] = nums[j];
                while(i<j&&nums[i]<=v) i++;
                nums[j] = nums[i];
            }
            nums[i] = v;
            qsort(nums, l, i-1);
            qsort(nums, i+1, r);
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
    
    Solution *solution = new Solution();
    cout<<solution->majorityElement(nums);
    
    return 0;
    
}
