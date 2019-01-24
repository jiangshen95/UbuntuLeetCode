#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
        	int index = abs(nums[i]) - 1;
        	if(nums[index] < 0) result.push_back(index + 1);
        	nums[index] = -nums[index];
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
	vector<int> result = solution->findDuplicates(nums);
	
	for(int x : result) cout<<x<<" ";
	
	return 0;
	
}
