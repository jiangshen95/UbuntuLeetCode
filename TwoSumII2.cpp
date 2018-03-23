#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        vector<int> result;
        
        for(int i=0;i<numbers.size()-1;i++){
            int l = i+1, r = numbers.size()-1;
            int gap = target - numbers[i];
            while(l <= r){
                int m = l + (r-l)/2;
                if(numbers[m] == gap){
                    return vector<int>{i+1, m+1};
                }else if(numbers[m] > gap){
                    r = m-1;
                }else l = m+1;
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
