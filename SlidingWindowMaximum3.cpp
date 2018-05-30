#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    	
    	if(nums.empty() || k <= 0) return vector<int>();
    	
    	int n = nums.size();
        
        vector<int> left_max(n), right_max(n);
        
        for(int i = 0;i < n;i ++) {
        	if(i % k == 0) left_max[i] = nums[i];
        	else{
        		left_max[i] = max(nums[i], left_max[i - 1]);
			}
			
			if((n - i) % k == 0 || n - i - 1 == n - 1)  right_max[n - i - 1] = nums[n - i - 1];
			else{
				right_max[n - i - 1] = max(nums[n - i - 1], right_max[n - i]);
			}
		}
		
		vector<int> result;
		for(int i = 0;i <= n - k;i++) {
			result.push_back(max(right_max[i], left_max[i + k - 1]));
		}
		
		return result;
        
    }
};

int main() {
	
	int n;
	cin>>n;
	
	vector<int> nums;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		nums.push_back(num);
	}
	
	int k;
	cin>>k;
	
	Solution *solution = new Solution();
	vector<int> result = solution->maxSlidingWindow(nums, k);
	
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<"  ";
	}
	
	return 0;
	
}
