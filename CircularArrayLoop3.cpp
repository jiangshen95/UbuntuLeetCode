#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
    	int n = nums.size();
    	for(int i = 0; i < n; i++) {
    		if(nums[i] == 0) continue;
    		
    		//slow/fast pointer
    		int j = i, k = getIndex(i, nums);
    		while(nums[k] * nums[i] > 0 && nums[getIndex(k, nums)] * nums[i] > 0) {
    			if(j == k) {
    				if(j == getIndex(j, nums)) break;
    				return true;
				}
				j = getIndex(j, nums);
				k = getIndex(getIndex(k, nums), nums);
			}
			
			j = i;
			int next = getIndex(j, nums);
			while(nums[j] * nums[next] > 0) {
				next = getIndex(j, nums);
				nums[j] = 0;
				j = next;
			}
		}
		return false;
    }
    
    int getIndex(int i, vector<int>& nums) {
    	int n = nums.size();
    	return ((i + nums[i]) % n + n) % n;
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
