#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0, sum = 0;
        for(int num : nums) {
        	sum = (sum + num) * num;
        	result = max(result, sum);
		}
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
	cout<<solution->findMaxConsecutiveOnes(nums);
	
	return 0;
}
