#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        
        int i2 = 0, i3 = 0, i5 = 0;
        vector<int> nums(1, 1);
        
        while(nums.size() < n) {
        	if(nums[i2] * 2 <= nums.back()) i2 ++;
        	if(nums[i3] * 3 <= nums.back()) i3 ++;
        	if(nums[i5] * 5 <= nums.back()) i5 ++;
        	nums.push_back(min(nums[i2] * 2, min(nums[i3] * 3, nums[i5] * 5)));
		}
		
		return nums.back();
    }
};

int main() {
	
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->nthUglyNumber(n);
	
	return 0; 
	
}
