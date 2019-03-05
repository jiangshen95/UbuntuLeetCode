#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
    	int smi = 0;
    	vector<pair<int, int> > ranges;
        for(int i = 1; i < nums.size(); i++) {
        	for(auto range : ranges) {
        		if(nums[i] > range.first && nums[i] < range.second) return true;
			}
        	if(nums[i] >= nums[i - 1]) continue;
        	if(nums[i] > nums[smi]) return true;
        	if(i - 1 > smi)
        		ranges.push_back(make_pair(nums[smi], nums[i - 1]));
        	smi = i;
		}
		
		return false;
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
	solution->find132pattern(nums) ? cout<<"true" : cout<<"false";
	
	return 0;
	
}
