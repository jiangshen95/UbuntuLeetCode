#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size() - 1;
        int lo = 1, hi = n;
        while(lo < hi) {
        	int mid = lo + (hi - lo) / 2;
        	int count = 0;
	        for(int i=0;i<nums.size();i++) {
	        	if(nums[i] <= mid) count ++;
			}
			
			if(count <= mid) lo = mid + 1;
			else hi = mid;
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
