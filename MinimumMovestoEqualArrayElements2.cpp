#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int min_num = INT_MAX;
        for(int num : nums) min_num = min(num, min_num);
        
        int count = 0;
        for(int num : nums) count += num - min_num;
        
        return count;
        
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
	cout<<solution->minMoves(nums);
	
	return 0;
	
}
