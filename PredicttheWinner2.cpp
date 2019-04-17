#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return canWin(nums, 0, nums.size() - 1, 0, 0, 0);
    }
    
    bool canWin(vector<int>& nums, int start, int end, int sum1, int sum2, int times) {
    	if(start > end) {
    		if(times % 2 == 0) return sum1 >= sum2;
			else return sum1 < sum2;
		}
		if(times % 2 == 0) {
			return !canWin(nums, start + 1, end, sum1 + nums[start], sum2, times + 1) || !canWin(nums, start, end - 1, sum1 + nums[end], sum2, times + 1);
		}else {
			return !canWin(nums, start + 1, end, sum1, sum2 + nums[start], times + 1) || !canWin(nums, start, end - 1, sum1, sum2 + nums[end], times + 1);
		}
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
	solution->PredictTheWinner(nums) ? cout<<"true" : cout<<"false";
	
	return 0;
}
