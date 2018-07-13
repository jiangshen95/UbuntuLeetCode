#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int tortoise = nums[0];
        int hare = nums[0];
        do {
        	tortoise = nums[tortoise];
        	hare = nums[nums[hare]];
		} while(tortoise != hare);
		
		int part1 = nums[0];
		int part2 = hare;
		while(part1 != part2) {
			part1 = nums[part1];
			part2 = nums[part2];
		}
		
		return part1;
        
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
