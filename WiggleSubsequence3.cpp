#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        if(nums.size() < 2) return nums.size();
        
        vector<int> up(nums.size(), 1);
        vector<int> down(nums.size(), 1);
        
        for(int i = 1; i < nums.size(); i++) {
        	if(nums[i] > nums[i - 1]){
        		up[i] = down[i - 1] + 1;
        		down[i] = down[i - 1];
			}
        	else if(nums[i] < nums[i - 1]) {
        		down[i] = up[i - 1] + 1;
        		up[i] = up[i - 1];
			}
        	else {
        		down[i] = down[i - 1];
        		up[i] = up[i - 1];
			}
		}
		
		return max(up.back(), down.back());
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
	cout<<solution->wiggleMaxLength(nums);
	
	return 0;
	
}
