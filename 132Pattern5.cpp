#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
    	int n = nums.size();
    	vector<int> mn(nums.begin(), nums.end());
    	for(int i = 1; i < n; i++) {
    		mn[i] = min(mn[i], mn[i - 1]);
		}
		
		for(int j = n - 1, top = n; j >= 0; j--) {
			if(nums[j] <= mn[j]) continue;
			while(top < n && mn[top] <= mn[j]) top++;
			if(top < n && nums[j] > mn[top]) return true;
			mn[--top] = nums[j];
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
