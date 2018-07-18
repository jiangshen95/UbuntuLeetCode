#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
    	
    	int n = nums.size();
    	
    	vector<int> result;
    	
    	for(auto num : nums) {
    		
    		auto it = lower_bound(result.begin(), result.end(), num);
    		if(it == result.end()) result.push_back(num);
    		else *it = num;
    		
		}
		
		return result.size();
        
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
