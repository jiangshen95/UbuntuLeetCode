#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        if(nums.size() < 2) return nums.size();
        
        int diff = nums[1] - nums[0];
        int count = diff == 0 ? 1 : 2;
        int prediff = diff;
        for(int i = 1; i < nums.size() - 1; i++) {
        	diff = nums[i + 1] - nums[i];
        	if((prediff <= 0 && diff > 0) || (prediff >= 0 && diff < 0)) {
        		count++;
        		prediff = diff;
			}
		}
		
		return count;
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
