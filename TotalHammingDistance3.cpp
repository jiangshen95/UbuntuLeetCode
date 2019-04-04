#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
    	int count = 0;
        for(int i = 0; i < 32; i++) {
        	int cnt = 0;
        	for(int num : nums) cnt += (num >> i) & 1;
        	count += (nums.size() - cnt) * cnt;
		}
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
	cout<<solution->totalHammingDistance(nums);
	
	return 0;
}
