#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
    	unordered_map<int, unordered_map<int, int> > m;
        return findTargetSum(nums, 0, 0, S, m);
    }
    
    int findTargetSum(vector<int>& nums, int pos, int sum, int S, unordered_map<int, unordered_map<int, int> >& m) {
    	if(pos == nums.size() && sum == S) return 1;
    	if(pos == nums.size() && sum != S) return 0;
    	if(m.find(pos) != m.end() && m[pos].find(sum) != m[pos].end()) return m[pos][sum];
    	int result = findTargetSum(nums, pos + 1, sum + nums[pos], S, m) + findTargetSum(nums, pos + 1, sum - nums[pos], S, m);
    	m[pos][sum] = result;
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
	
	int S;
	cin>>S;
	
	Solution *solution = new Solution();
	cout<<solution->findTargetSumWays(nums, S);
	
	return 0;
}
