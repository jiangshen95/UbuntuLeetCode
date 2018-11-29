#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
	/*
	* Binary search
	*/
    int splitArray(vector<int>& nums, int m) {
        long left = 0, right = 0;
        for(int num : nums) {
        	//left = max(left, num);
        	if(num > left) left = num;
        	right += num;
		}
		
		while(left < right) {
			long mid = left + (right - left) / 2;
			int sum = 0, count = 1;
			for(int i = 0; i < nums.size(); i++) {
				if(sum + nums[i] > mid) {
					sum = 0;
					count++;
				}
				sum += nums[i];
			}
			
			if(count <= m) right = mid;
			else left = mid + 1;
		}
		
		return left;
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
