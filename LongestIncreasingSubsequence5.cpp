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
    		int i = binarySearch(dp, 0, len, num);
    		if(i < 0) {
    			i = -(i + 1);
			}
			dp[i] = num;
			if(i == len) len ++;
		}
		
		return len;
        
    }
    
    int binarySearch(vector<int> dp, int begin, int end, int num) {
    	
    	int i = begin, j = end - 1;
    	while(i <= j) {
    		int mid = i + (j - i) / 2;
    		if(num > dp[mid]) i = mid + 1;
    		else if(num < dp[mid]) j = mid - 1;
    		else return mid;
		}
		
		return -i - 1;
    	
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
