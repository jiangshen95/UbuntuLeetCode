#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        if(nums.size() < 2) return nums.size();
        
        int i = 0;
        int del = 0;
        int direct = 0;
        while(i < nums.size()) {
        	while(i + 1 < nums.size() && nums[i + 1] == nums[i]) {
        		i++;
        		del++;
			}
        	int j = i;
        	bool isright = true;
        	if(j + 1 < nums.size() && nums[j + 1] > nums[j]) {
        		if(direct == -1) isright = false;
        		direct = 1;
        		while(j + 1 < nums.size() && nums[j + 1] >= nums[j]) j++;
			}else if(j + 1 < nums.size() && nums[j + 1] < nums[j]) {
				if(direct == 1) isright = false;
				direct = -1;
				while(j + 1 < nums.size() && nums[j + 1] <= nums[j]) j++;
			}
			if(j > i) del += isright ? j - i - 1 : j - i;
			i = j + 1;
		}
        
        return nums.size() - del;
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
