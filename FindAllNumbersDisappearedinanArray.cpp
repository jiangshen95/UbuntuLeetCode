#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++) {
        	if(nums[i] != i + 1) {
        		int t = nums[i];
        		if(nums[t - 1] != t) {
        			nums[i] = nums[t - 1];
        			nums[t - 1] = t;
        			i--;
				}
			}
		}
		
		vector<int> result;
		for(int i = 0; i < nums.size(); i++)
			if(nums[i] != i + 1) result.push_back(i + 1);
			
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
	vector<int> result = solution->findDisappearedNumbers(nums);
	
	for(int r : result) cout<<r<<" ";
	
	return 0;
	
}
