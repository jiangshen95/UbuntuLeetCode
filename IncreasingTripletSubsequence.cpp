#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX, b = INT_MAX;
        
        for(int i = 0; i < nums.size(); i++) {
        	if(i == 0 || nums[i] <= a) {
        		a = nums[i];
			}else if(nums[i] > a) {
				if(nums[i] <= b) b = nums[i];
				else return true;
			}
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
	solution->increasingTriplet(nums) ? cout<<"true" : cout<<"false";
	
	return 0;
	
}
