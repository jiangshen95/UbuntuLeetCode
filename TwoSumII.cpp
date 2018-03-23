#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector<int> result;
        
        int l = 0, r = numbers.size()-1;
        
        while(l < r){
            if(numbers[l]+numbers[r] < target) l++;
            else if(numbers[l]+numbers[r] > target) r--;
            else{
                result.push_back(l+1);
                result.push_back(r+1);
                break;
            }
        }
        
        return result;
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
    
    int target;
    cin>>target;
    
    Solution *solution = new Solution();
    vector<int> result = solution->twoSum(nums, target);
    
    for(int i=0;i<result.size();i++) cout<<result[i]<<"  ";
    
    return 0;
}
