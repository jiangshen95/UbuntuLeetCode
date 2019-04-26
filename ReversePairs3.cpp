#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return mergeSort(nums, 0, nums.size() - 1);
    }
    
    int mergeSort(vector<int>& nums, int left, int right) {
    	if(left >= right) return 0;
    	int mid = left + (right - left) / 2;
    	int res = mergeSort(nums, left, mid) + mergeSort(nums, mid + 1, right);
    	for(int i = left, j = mid + 1; i <= mid; i++) {
    		while(j <= right && nums[i] / 2.0 > nums[j]) j++;
    		res += j - (mid + 1);
		}
		
		int i = left, j = mid + 1;
		vector<int> cache;
		while(i <= mid && j <= right) {
			if(nums[i] < nums[j]) cache.push_back(nums[i++]);
			else cache.push_back(nums[j++]);
		}
		while(i <= mid) cache.push_back(nums[i++]);
		while(j <= right) cache.push_back(nums[j++]);
		
		for(i = left; i <= right; i++) nums[i] = cache[i - left];
		
//		sort(nums.begin() + left, nums.begin() + right + 1);
		return res;
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
