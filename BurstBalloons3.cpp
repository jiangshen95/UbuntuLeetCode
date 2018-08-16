#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
    	
    	int n = nums.size();
    	if(n == 0) return 0;
    	
    	vector<vector<int> > memo(n, vector<int>(n, 0));
    	
    	return burst(memo, nums, 0, n - 1);
    	
    }
    
    int burst(vector<vector<int> >& memo, vector<int>& nums, int left, int right) {
    	
    	if(left > right) return 0;
    	
    	if(memo[left][right] > 0) return memo[left][right];
    	
    	for(int i = left; i <= right; i++) {
    		memo[left][right] = max(memo[left][right], burst(memo, nums, left, i - 1) + burst(memo, nums, i + 1, right) + (left - 1 >= 0 ? nums[left - 1] : 1) * nums[i] * (right + 1 < nums.size() ? nums[right + 1] : 1));
		}
    	
    	return memo[left][right];
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
	cout<<solution->maxCoins(nums);
	
	return 0;
	
}
