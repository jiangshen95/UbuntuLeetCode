#include<iostream>
#include<vector>
#include<algorithm>
#include<bitset>

using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum = 0;
        for(int num : nums) sum += num;
        
        if(sum % 2) return false;
        
        sum /= 2;
        
        bitset<10001> bits(1);
        for(int num : nums) bits |= (bits << num);
        return bits[sum];
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
	solution->canPartition(nums) ? cout<<"true" : cout<<"false";
	
	return 0;
	
}
