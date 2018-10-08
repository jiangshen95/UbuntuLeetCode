#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
    	
    	sort(nums.begin(), nums.end());
        
        vector<int> dp(nums.size(), 1);
        vector<int> path(nums.size(), -1);
        
        int max_size = 0;
        
        int index = -1;
        
        for(int i = 0; i < nums.size(); i++) {
        	for(int j = 0; j < i; j++) {
        		if(nums[i] % nums[j] == 0) {
        			if(dp[j] + 1 > dp[i]) {
        				dp[i] = dp[j] + 1;
        				path[i] = j;
					}
				}
			}
			//max_size = max(max_size, dp[i]);
			if(dp[i] > max_size) {
				max_size = dp[i];
				index = i;
			}
		}
		
		vector<int> result;
		
		while(index >= 0) {
			result.insert(result.begin(), nums[index]);
			index = path[index];
		}
		
//		for(int i = 0; i < nums.size(); i++) {
//			if(dp[i] == max_size) {
//				
//				int j = i;
//				while(j >= 0) {
//					result.insert(result.begin(), nums[j]);
//					j = path[j];
//				}
//				break;
//			}
//		}
		
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
	
	Solution *solution = new Solution();
	vector<int> result = solution->largestDivisibleSubset(nums);
	
	for(int i = 0; i < result.size(); i++) cout<<result[i]<<"  ";
	
	return 0;
	
}
