#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int n = nums.size();
        int sum = (n + 1) * n / 2;
        int sum_of_nums = 0;
        for(int i=0;i<nums.size();i++) sum_of_nums += nums[i];
        return sum - sum_of_nums;
        
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
	cout<<solution->missingNumber(nums);
	
	return 0;
	
}
