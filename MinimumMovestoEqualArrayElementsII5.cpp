#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
    	sort(nums.begin(), nums.end());
    	long long sum = accumulate(nums.begin(), nums.end(), 0);
    	long long curSum = 0;
    	long long res = LONG_MAX;
    	int n = nums.size();
    	for(int i = 0; i < n; i++) {
    		long long k = nums[i];
    		curSum += k;
    		res = min(res, 2 * (i + 1) * k - n * k + sum - 2 * curSum);
		}
		return res;
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
	cout<<solution->minMoves2(nums);
	
	return 0;
	
}
