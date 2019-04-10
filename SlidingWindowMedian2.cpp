#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        multiset<int> window(nums.begin(), nums.begin() + k);
        auto mid = next(window.begin(), k / 2);
        for(int i = k; i <= nums.size(); i++) {
        	result.push_back(((double)*mid + *prev(mid, 1 - k % 2)) / 2.0);
            if(i == nums.size()) break;
        	window.insert(nums[i]);
        	if(nums[i] < *mid) --mid;
        	if(nums[i - k] <= *mid) ++mid;
        	window.erase(window.lower_bound(nums[i - k]));
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
	
	int k;
	cin>>k;
	
	Solution *solution = new Solution();
	vector<double> result = solution->medianSlidingWindow(nums, k);
	
	for(double m : result) cout<<m<<" ";
	
	return 0;
}
