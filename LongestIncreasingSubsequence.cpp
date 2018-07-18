/*
** Time Limit Exceeded
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	
    	int result = 0;
        
        for(int i=0;i<nums.size();i++) {
        	result = max(result, helper(nums, i));
		}
		
		return result;
        
    }
    
    int helper(vector<int> nums, int index) {
    	
    	int count = 1;
    	
    	for(int i = index + 1;i<nums.size();i++) {
    		if(nums[i] > nums[index]) {
    			int temp = 1 + helper(nums, i);
    			if(temp > count) count = temp;
			}
		}
		
		return count;
	} 
    
};

int main() {
	
	int n;
	cin>>n;
	
	vector<int> nums;
	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		nums.push_back(num);
	} 
	
	Solution *solution = new Solution();
	cout<<solution->lengthOfLIS(nums);
	
	return 0;
	
}
