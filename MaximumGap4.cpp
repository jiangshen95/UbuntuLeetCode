#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2) return 0;
        
        int m = 0;
        for(int i=0;i<nums.size();i++) m = max(m, nums[i]);
        
        int exp = 1;
        while(m/exp){
            
            vector<int> aux(nums.size());
            vector<int> count(10, 0);
            
            for(int i=0;i<nums.size();i++){
                count[(nums[i]/exp)%10]++;
            }
            
            for(int i=1;i<10;i++) count[i] += count[i-1];
            
            for(int i=nums.size()-1;i>=0;i--) aux[--count[(nums[i]/exp)%10]] = nums[i];
            //for(int i=0;i<nums.size();i++) aux[--count[(nums[i]/exp)%10]] = nums[i]; 从前往后循环不对
            
            for(int i=0;i<nums.size();i++) nums[i] = aux[i];
            
            exp *= 10;
        }
        
        for(int i=0;i<nums.size();i++) cout<<nums[i]<<"  ";
        
        int maxGap = 0;
        for(int i=0;i<nums.size()-1;i++) maxGap = max(maxGap, nums[i+1]-nums[i]);
        
        return maxGap;
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
