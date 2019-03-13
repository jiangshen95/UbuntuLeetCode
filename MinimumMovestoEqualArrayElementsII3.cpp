#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int result = 0;
        int i = 0, j = nums.size() - 1;
        while(i < j) {
        	result += nums[j--] - nums[i++];
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
	cout<<solution->minMoves2(nums);
	
	return 0;
	
}
