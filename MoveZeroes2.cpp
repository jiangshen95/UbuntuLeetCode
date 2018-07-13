#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int lastNoneZeroFoundAt = 0;
        
        for(int i=0;i<nums.size();i++) {
        	if(nums[i] != 0) nums[lastNoneZeroFoundAt++] = nums[i];
		}
        
        for(int i=lastNoneZeroFoundAt;i<nums.size();i++) nums[i] = 0;
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
	solution->moveZeroes(nums);
	
	for(int i=0;i<n;i++) cout<<nums[i]<<"  ";
	
	return 0;
}
