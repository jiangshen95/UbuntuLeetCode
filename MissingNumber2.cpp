#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        int missing = nums.size();
        
        for(int i=0;i<nums.size();i++) {
        	missing ^= i ^ nums[i];
		}
		
		return missing;
        
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
