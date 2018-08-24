#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int m = nums1.size(), n = nums2.size();
        
        int i = 0;
        vector<int> nums;
        while(i <= m && i <= k) {
        	
        	if(k - i <= n) {
        		nums = max(nums, mergeArray(maxNumber(nums1, i), maxNumber(nums2, k - i)));
			}
        	i++;
		}
		
		return nums;
        
    }
    
    vector<int> mergeArray(vector<int> nums1, vector<int> nums2) {
    	
    	vector<int> nums;
    	while(!nums1.empty() || !nums2.empty()) {
    		
    		if(nums1 > nums2) {
    			nums.push_back(nums1.front());
    			nums1.erase(nums1.begin());
			}else {
				nums.push_back(nums2.front());
				nums2.erase(nums2.begin());
			}
    		
		}
		return nums;
    	
	}
    
    vector<int> maxNumber(vector<int> nums, int k) {
    	
    	while(nums.size() > k) {
    		int i = 0, n = nums.size();
    		for(; i < n - 1; i++) {
    			if(nums[i] < nums[i + 1]) {
    				nums.erase(nums.begin() + i);
    				break;
				}
			}
			if(i == n - 1) nums.erase(nums.begin() + i);
    		
		}
		return nums;
    	
	}
};

int main() {
	
	int m, n;
	cin>>m>>n;
	
	vector<int> nums1, nums2;
	for(int i = 0; i < m; i++) {
		int num;
		cin>>num;
		nums1.push_back(num);
	}
	for(int i = 0; i < n; i++) {
		int num;
		cin>>num;
		nums2.push_back(num);
	}
	
	int k;
	cin>>k;
	
	Solution *solution = new Solution();
	vector<int> result = solution->maxNumber(nums1, nums2, k);
	
	for(int i = 0; i < result.size(); i++) cout<<result[i]<<"  ";
	
	return 0;
}
