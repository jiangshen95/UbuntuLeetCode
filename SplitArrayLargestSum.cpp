/*
* Time Limit Exceeded
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int result = INT_MAX;
        splitArray(nums, 0, 0, m, result);
        return result;
    }
    
    int splitArray(vector<int>& nums, int index, int max_sum, int m, int& min_max_sum) {
    	if(m == 0 || index >= nums.size()) return 0;
    	int sum = 0;
    	int max_last_sum = 0;
    	for(int i = index; i <= nums.size() - m; i++) {
    		sum += nums[i];
    		max_sum = max(max_sum, sum);
    		int t = splitArray(nums, i + 1, max_sum, m - 1, min_max_sum);
    		max_last_sum = max(max_last_sum, t);
//    		min_max_sum = min(min_max_sum, max(max_sum, t));
//    		if(t != 0) min_max_sum = min(min_max_sum, t);
//    		else if(i == nums.size() - 1) min_max_sum = min(min_max_sum, max_sum);
		}
		
		max_sum = max(max_sum, max_last_sum);
		
		min_max_sum = min(min_max_sum, max_sum);
		cout<<"index: "<<index<<"  max_sum: "<<max_sum<<"  m: "<<m<<endl;
		
		
		return max_sum;
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
	
	int m;
	cin>>m;
	
	Solution *solution = new Solution();
	cout<<solution->splitArray(nums, m);
	
	return 0;
	
}
