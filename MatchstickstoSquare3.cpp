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
        int n = nums.size();
        int all = (1 << n) - 1;
        vector<int> masks;
        vector<bool> validHalf(1 << n, false);
        
        for(int i = 1; i <= all; i++) {
        	int curSum = 0;
        	for(int j = 0; j < 15; j++) {
        		if((1 << j) & i) curSum += nums[j];
			}
			
			if(curSum == len) {
				for(int mask : masks) {
					if(mask & i) continue;
					int half = mask | i;
					validHalf[half] = true;
					if(validHalf[all ^ half]) return true;
				}
				masks.push_back(i);
			}
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
