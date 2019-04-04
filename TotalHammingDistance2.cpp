#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = 0;
        for(int num : nums) n |= num;
        int t = 0, count = 0;
        while(n > 0) {
        	int cnt = 0;
        	for(int num : nums) {
        		if(((num >> t) ^ n) & 1) cnt++;
			} 
			count += (nums.size() - cnt) * cnt;
			n >>= 1;
			t++;
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
