#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
    	int n = nums.size();
    	int i = 0;
    	while(i < n) {
    		while(i < n - 1 && nums[i] >= nums[i + 1]) i++;
    		int j = i + 1;
    		while(j < n - 1 && nums[j] <= nums[j + 1]) j++;
    		
    		for(int k = j + 1; k < n; k++)
    			if(nums[k] > nums[i] && nums[k] < nums[j]) return true;
    		i = j + 1;
		}
		
		return false;
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
	solution->find132pattern(nums) ? cout<<"true" : cout<<"false";
	
	return 0;
	
}
