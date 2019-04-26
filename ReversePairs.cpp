/*
 * Time Limit Exceeded
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
        	for(int j = i + 1; j < nums.size(); j++) {
        		if(nums[i] > 0 && nums[j] < 0) count++;
        		else if(nums[i] < 0 && nums[j] > 0) continue;
        		else if(nums[i] - nums[j] > nums[j]) count++;
			}
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
	
	Solution *solution = new Solution();
	cout<<solution->reversePairs(nums);
	
	return 0;
}
