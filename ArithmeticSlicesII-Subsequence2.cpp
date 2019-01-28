#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        vector<unordered_map<int, int> > dp(A.size());
        int result = 0;
        for(int i = 0; i < A.size(); i++) {
        	for(int j = 0; j < i; j++) {
        		long long delta = (long long)A[i] - A[j];
        		if(delta > INT_MAX || delta < INT_MIN) continue;
        		int diff = (int)delta;
        		dp[i][diff]++;
        		if(dp[j].find(diff) != dp[j].end()) {
        			dp[i][diff] += dp[j][diff];
        			result += dp[j][diff];
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
	
	Solution *solution = new Solution();
	cout<<solution->numberOfArithmeticSlices(nums);
	
	return 0;
	
}
