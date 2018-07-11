#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        
        int l = 0, r = nums.size();
        while(l < r) {
        	int mid = (l + r) / 2;
        	if(nums[mid] > mid) r = mid;
        	else l = mid + 1;
		}
		
		return l;
        
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
	cout<<solution->missingNumber(nums);
	
	return 0;
	
}
