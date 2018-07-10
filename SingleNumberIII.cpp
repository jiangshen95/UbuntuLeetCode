#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        int diff = 0;
        for(int i=0;i<nums.size();i++) diff ^= nums[i];
        diff &= -diff;  // 补码的方式相与，可以获得最右侧的一位1
        
        vector<int> result(2, 0);
        for(int i=0;i<nums.size();i++) {
        	if(nums[i] & diff) result[0] ^= nums[i];
        	else result[1] ^= nums[i];
		}
		
		return result;
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
	vector<int> result = solution->singleNumber(nums);
	
	for(int i=0;i<result.size();i++) cout<<result[i]<<"  ";
	
	return 0; 
	
}
