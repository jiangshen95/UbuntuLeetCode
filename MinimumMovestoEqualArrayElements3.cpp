#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {
        
        int min_num = INT_MAX;
        long long sum;
        
        for(int num : nums) {
        	sum += num;
        	min_num = min(min_num, num);
		}
        
        return sum - min_num * nums.size();
        
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
