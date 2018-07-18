#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	
    	return lengthOfLIS(nums, INT_MIN, 0);
        
    }
    
    int lengthOfLIS(vector<int> nums, int prev, int curPos) {
    	
    	if(curPos == nums.size() - 1) return 0;
    	int taken = 0;
    	if(nums[curPos] > prev) {
    		taken = 1 + lengthOfLIS(nums, nums[curPos], curPos + 1);
		}
		int nottaken = lengthOfLIS(nums, prev, curPos + 1);
		
		return max(taken, nottaken);
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
