#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> result;
        multiset<int> small, large;
        for(int i = 0; i <= nums.size(); i++) {
        	if(i < k) {
        		if(small.size() <= large.size()) {
        			if(large.empty() || nums[i] <= *large.begin()) small.insert(nums[i]);
        			else {
        				small.insert(*large.begin());
        				large.insert(nums[i]);
        				large.erase(large.begin());
					}
				}else {
					if(nums[i] >= *small.rbegin()) large.insert(nums[i]);
					else {
						small.insert(nums[i]);
						large.insert(*small.rbegin());
						small.erase(--small.end());
					}
				}
			}
			else {
				int mid = *small.rbegin();
				if(k & 1) result.push_back(mid);
				else {
					result.push_back(((double)mid + *large.begin()) / 2);
				}
				if(i == nums.size()) break;
				if(nums[i - k] <= mid) {
					small.erase(small.find(nums[i - k]));
					if(nums[i] > mid) {
						large.insert(nums[i]);
						small.insert(*large.begin());
						large.erase(large.begin());
					}else {
						small.insert(nums[i]);
					}
				}else {
					large.erase(large.find(nums[i - k]));
					if(nums[i] > mid) large.insert(nums[i]);
					else {
						small.insert(nums[i]);
						large.insert(*small.rbegin());
						small.erase(--small.end());
					}
				}
			}
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
