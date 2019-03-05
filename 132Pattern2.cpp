#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
    	int mn = INT_MAX, n = nums.size();
    	for(int j = 0; j < n; j++) {
    		mn = min(mn, nums[j]);
    		if(mn == nums[j]) continue;
    		for(int i = n - 1; i > j; i--) {
    			if(nums[i] > mn && nums[i] < nums[j]) return true;
			}
		}
		return false;
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
	solution->find132pattern(nums) ? cout<<"true" : cout<<"false";
	
	return 0;
	
}
