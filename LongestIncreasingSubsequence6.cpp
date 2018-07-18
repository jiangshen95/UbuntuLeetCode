#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	
    	int n = nums.size();
    	
    	vector<int> dp(n, 0);
    	int len = 0;
    	
    	for(auto num : nums) {
    		
    		int i = 0, j = len;
    		while(i < j) {
    			int m = i + (j - i) / 2;
    			if(num > dp[m]) i = m + 1;
    			else j = m;
			}
			
			dp[i] = num;
			if(i == len) len ++;
		}
		
		return len;
        
    }
    
};

int main() {
	
	int n;
	cin>>n;
	
	vector<int> nums;
	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		nums.push_back(num);
	} 
	
	Solution *solution = new Solution();
	cout<<solution->lengthOfLIS(nums);
	
	return 0;
	
}
