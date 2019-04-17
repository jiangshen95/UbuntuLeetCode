#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return canWin(nums, 0, nums.size() - 1) >= 0;
    }
    
    int canWin(vector<int>& nums, int start, int end) {
    	if(start == end) return nums[start];
    	return max(nums[start] - canWin(nums, start + 1, end), nums[end] - canWin(nums, start, end - 1));
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
