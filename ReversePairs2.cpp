#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int res = 0, n = nums.size();
        vector<int> v = nums, bit(n + 1);
		sort(v.begin(), v.end());
		unordered_map<int, int> m;
		for(int i = 0; i < n; i++) m[v[i]] = i + 1;
		for(int i = n - 1; i >= 0; i--) {
			res += getSum(binarySearch(nums[i] / 2.0, v) + 1, bit);
//			res += getSum(lower_bound(v.begin(), v.end(), nums[i] / 2.0) - v.begin(), bit);
			update(m[nums[i]], bit);
		}
		return res;
    }
    
	int binarySearch(float t, vector<int>& v) {
		int l = 0, r = v.size() - 1;
		while(l <= r) {
			int mid = (l + r) / 2;
			if(v[mid] >= t) r = mid - 1;
			else l = mid + 1;
		}
		return r;
	}
    
    void update(int i, vector<int>& bit) {
    	while(i < bit.size()) {
    		bit[i] += 1;
    		i += (i & -i);
		}
	}
	
	int getSum(int i, vector<int>& bit) {
		int sum = 0;
		while(i > 0) {
			sum += bit[i];
			i -= (i & -i);
		}
		return sum;
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
	cout<<solution->reversePairs(nums);
	
	return 0;
}
