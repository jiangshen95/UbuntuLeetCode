#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size() <= 3) return false;
        int sum = 0;
        for(int num : nums) sum += num;
        if(sum % 4) return false;
        int len = sum / 4;
        vector<int> sums(4, 0);
        sort(nums.rbegin(), nums.rend());
        return makeSide(nums, sums, 0, len);
    }
    
    bool makeSide(vector<int>& nums, vector<int>& sums, int pos, int len) {
    	if(pos >= nums.size()) {
    		return sums[0] == len && sums[1] == len && sums[2] == len;
		}
		for(int i = 0; i < 4; i++) {
			if(sums[i] + nums[pos] > len) continue;
			sums[i] += nums[pos];
			if(makeSide(nums, sums, pos + 1, len)) return true;
			sums[i] -= nums[pos];
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
	solution->makesquare(nums) ? cout<<"true" : cout<<"false";
	
	return 0;
}
