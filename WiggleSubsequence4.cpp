#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        if(nums.size() < 2) return nums.size();
        
        int up = 1, down = 1;
        
        for(int i = 1; i < nums.size(); i++) {
        	if(nums[i] > nums[i - 1]) up = down + 1;
        	else if(nums[i] < nums[i - 1]) down = up + 1;
		}
		
		return max(up, down);
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
	cout<<solution->wiggleMaxLength(nums);
	
	return 0;
	
}
