#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
    	int n = nums.size(), third = INT_MIN;
    	stack<int> s;
    	for(int i = n - 1; i >= 0; i--) {
			if(nums[i] < third) return true;
			while(!s.empty() && nums[i]  > s.top()) {
				third = s.top();
				s.pop();
			}
    		s.push(nums[i]);
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
