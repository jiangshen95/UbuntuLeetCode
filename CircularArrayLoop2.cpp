#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
    	int n = nums.size();
        for(int i = 0; i < n; i++) {
        	if(nums[i] == 0) continue;
        	int cur = nums[i];
        	nums[i] = 0;
        	int next = ((i + cur) % n + n) % n;
        	if(next == i) continue;
        	while(cur * nums[next] > 0) {
        		cur = nums[next];
        		nums[next] = 0;
        		next = ((next + cur) % n + n) % n;
			}
			if(next == i) return true;
		}
		return false;
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
	solution->circularArrayLoop(nums) ? cout<<"true" : cout<<"false";
	
	return 0;
	
}
