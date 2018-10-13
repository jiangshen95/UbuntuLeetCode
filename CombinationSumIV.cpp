/*
** Time Limit Exceeded
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
    	sort(nums.begin(), nums.end());
        return combinationSum4(nums, target, 0);
    }
    
    int combinationSum4(vector<int>& nums, int target, int sum) {
    	if(sum > target) return 0;
    	if(sum == target) return 1;
    	
    	int count = 0;
    	for(int num : nums) {
    		if(sum + num <= target)
    		count += combinationSum4(nums, target, sum + num);
    		else break;
		}
		
		return count;
	}
};

int main() {
	
	int n;
	cin>>n;
	
	vector<int> nums;
	for(int i = 0; i < n; i++) {
		int num;
		cin>>num;
		nums.push_back(num);
	}
	
	int target;
	cin>>target;
	
	Solution *solution = new Solution();
	cout<<solution->combinationSum4(nums, target);
	
	return 0;
	
}
