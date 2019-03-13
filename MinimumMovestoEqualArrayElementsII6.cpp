#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
    	int result = 0, target = findNth(nums, 0, nums.size() - 1, nums.size() / 2 + 1);
        
        for(int num : nums) result += abs(num - target);
		
		return result;
    }
    
    int findNth(vector<int>& nums, int l, int r, int n) {
    	int i = l, j = r;
    	int v = nums[(l + r) / 2];
    	while(i <= j) {
    		while(nums[i] < v) i++;
    		while(nums[j] > v) j--;
    		if(i >= j) break;
    		swap(nums[i++], nums[j--]);
		}
		if(i - l + 1 > n) return findNth(nums, l, i - 1, n);
		else if(i - l + 1 == n && i == j) return nums[i];
		else return findNth(nums, j + 1, r, n - j + l - 1);
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
	cout<<solution->minMoves2(nums);
	
	return 0;
	
}
