/*
** Time Limit Exceeded
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
    	
        if(nums.size() == 1) return nums[0];
        
        int sum = 0;
        for(int i = 0; i < nums.size(); i++) {
        	vector<int> temp = nums;
        	int coins = nums[i] * (i > 0 ? nums[i - 1] : 1) * (i < nums.size() - 1 ? nums[i + 1] : 1);
        	temp.erase(temp.begin() + i);
        	coins += maxCoins(temp);
        	if(coins > sum) sum = coins;
		}
		
		return sum;
        
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
	cout<<solution->maxCoins(nums);
	
	return 0;
	
}
