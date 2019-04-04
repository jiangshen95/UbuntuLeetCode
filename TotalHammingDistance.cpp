/*
 * Time Limit Exceeded
*/
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int count = 0;
        for(int i = 0; i < nums.size(); i++) {
        	for(int j = i + 1; j < nums.size(); j++) {
        		count += hammingDistance(nums[i], nums[j]);
			}
		} 
		
		return count;
    }
    
    int hammingDistance(int x, int y) {
    	int n = x ^ y, count = 0;
    	while(n > 0) {
    		count++;
    		n &= n - 1;
		}
		return count;
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
	cout<<solution->totalHammingDistance(nums);
	
	return 0;
}
