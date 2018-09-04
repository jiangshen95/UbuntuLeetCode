#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
    	
    	long long sum = 0;
    	int res = 0;
    	
    	multiset<long long> sums;
		sums.insert(0);
		
		for(int i = 0; i < nums.size(); i++) {
			sum += nums[i];
			res += distance(sums.lower_bound(sum - upper), sums.upper_bound(sum - lower));
			sums.insert(sum);
		} 
		
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
	
	int lower, upper;
	cin>>lower>>upper;
	
	Solution *solution = new Solution();
	cout<<solution->countRangeSum(nums, lower, upper);
	
	return 0;
	
}
