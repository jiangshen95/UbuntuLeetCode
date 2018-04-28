#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int i = partition(nums, 0, nums.size() - 1);
        while(i != k - 1){
            if(i > k-1) {
                i = partition(nums, 0, i - 1);
            }
            else{
                i = partition(nums, i + 1, nums.size() - 1);
            }
        }
        
        return nums[i];
        
    }
    
    int partition(vector<int>& nums, int left, int right){
        int v = nums[left];
        int i = left;
        int j = right;
        while(i < j){
            while(i < j && nums[j] <= v) j--;
            nums[i] = nums[j];
            while(i < j && nums[i] >= v) i++;
            nums[j] = nums[i] ;
        }
        nums[i] = v;
        
        return i;
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
    cout<<solution->findKthLargest(nums, k);
    
    return 0;
    
}
