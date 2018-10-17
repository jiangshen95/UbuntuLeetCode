#include<iostream>
#include<vector>

using namespace std;

class Solution {
private:
	vector<int> nums;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
    	vector<int> result = nums;
        for(int i = 0; i < nums.size(); i++) {
        	int r = rand() % (i + 1);
        	result[i] = result[r];
        	result[r] = nums[i];
		}
		
		return result;
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
	
	Solution *solution = new Solution(nums);
	vector<int> shuf = solution->shuffle();
	for(int i = 0; i < shuf.size(); i++) cout<<shuf[i]<<"  ";
	cout<<endl;
	shuf = solution->reset();
	for(int i = 0; i < shuf.size(); i++) cout<<shuf[i]<<"  ";
	cout<<endl;
	
	return 0;
	
}
