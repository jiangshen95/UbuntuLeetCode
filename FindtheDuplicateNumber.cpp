#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size() - 1;
        int lo = 1, hi = n;
        while(lo < hi) {
        	int mid = (lo + hi) / 2;
        	int left = 0;
	        int right = 0;
	        for(int i=0;i<nums.size();i++) {
	        	if(nums[i] >= lo && nums[i] <= hi) {
	        		if(nums[i] > mid) right ++;
	        		else left ++;
				}
			}
			
			
			if(left > right) {
				hi = mid;
			}else {
				lo = mid + 1;
			}
		}
		
		return lo;
        
        
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
	cout<<solution->findDuplicate(nums);
	
	return 0;
	
}
