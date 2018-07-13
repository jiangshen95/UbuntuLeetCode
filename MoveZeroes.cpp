#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int i = 0, j = 0;
        for(i=0;i<nums.size();i++)
        	if(nums[i] == 0) break;
        for(j=i+1;j<nums.size();j++) {
        	if(nums[j] != 0) {
        		nums[i] = nums[j];
        		nums[j] = 0;
        		i ++;
			}
		}
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
	solution->moveZeroes(nums);
	
	for(int i=0;i<n;i++) cout<<nums[i]<<"  ";
	
	return 0;
}
