#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        qsort(nums, 0, nums.size()-1);
        int maxdif = 0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]>maxdif) maxdif = nums[i+1]-nums[i];
        }
        
        return maxdif;
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
    cout<<solution->maximumGap(nums);
    
    return 0;
    
}
