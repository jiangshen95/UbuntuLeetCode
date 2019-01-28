#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
        	int val = abs(nums[i]);
        	if(nums[val - 1] > 0) nums[val - 1] = -nums[val -  1];
		}
		
		vector<int> result;
		for(int i = 0; i < nums.size(); i++)
			if(nums[i] > 0) result.push_back(i + 1);
			
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
	vector<int> result = solution->findDisappearedNumbers(nums);
	
	for(int r : result) cout<<r<<" ";
	
	return 0;
	
}
