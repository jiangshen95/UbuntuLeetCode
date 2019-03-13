#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
    	
    	int n = nums.size(), mid = n / 2;
    	
    	nth_element(nums.begin(), nums.begin() + mid, nums.end());
    	
    	int result = 0;
        
        for(int num : nums) result += abs(num - nums[mid]);
		
		return result;
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
