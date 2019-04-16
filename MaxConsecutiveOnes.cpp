#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int result = 0, count = 0;
        for(int i = 0; i <= nums.size(); i++) {
        	if(i == nums.size() || nums[i] == 0) {
        		result = max(result, count);
        		count = 0;
			}else count++;
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
