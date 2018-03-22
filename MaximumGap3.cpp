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
            
            vector<vector<int> > temp(10);
            
            for(int i=0;i<nums.size();i++){
                temp[(nums[i]/exp)%10].push_back(nums[i]);
            }
            
            int index = 0;
            for(int i=0;i<10;i++){
                if(!temp[i].empty()){
                    for(int j=0;j<temp[i].size();j++) nums[index++] = temp[i][j];
                }
            }
            
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
