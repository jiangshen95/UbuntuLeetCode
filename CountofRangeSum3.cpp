#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
    	
    	if(nums.empty()) return 0;
    	
    	return countRangeSumSub(nums, 0, nums.size() - 1, lower, upper);
    	
    }
    
    int countRangeSumSub(vector<int> nums, int l, int r, int lower, int upper) {
    	
    	if(l == r) return nums[l] >= lower && nums[l] <= upper ? 1 : 0;
    	if(l > r) return 0;
    	
    	int mid = l + (r - l) / 2;
    	vector<long> sums;
    	long sum = 0;
    	for(int i = mid + 1; i <= r; i++) {
    		sum += nums[i];
    		sums.push_back(sum);
		}
		
		sort(sums.begin(), sums.end());
		
		int count = 0;
		sum = 0;
		for(int i = mid; i >= l; i--) {
			sum += nums[i];
			count += findIndex(sums, upper - sum + 0.5) - findIndex(sums, lower - sum - 0.5);
		}
    	
    	return count + countRangeSumSub(nums, l, mid, lower, upper) + countRangeSumSub(nums, mid + 1, r, lower, upper);
	}
	
	int findIndex(vector<long> nums, double num) {
		
		int l = 0, r = nums.size() - 1;
		
		while(l <= r) {
			
			int m = l + (r - l) / 2;
			if(nums[m] > num) r = m - 1;
			else if(nums[m] <= num) l = m + 1;
			
		}
		
		return l;
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
	
	int lower, upper;
	cin>>lower>>upper;
	
	Solution *solution = new Solution();
	cout<<solution->countRangeSum(nums, lower, upper);
	
	return 0;
	
}
