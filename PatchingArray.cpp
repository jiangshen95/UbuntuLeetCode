#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        
        long miss = 1;
        int i = 0;
        int step = 0;
        while(miss <= n) {
        	
        	if(i < nums.size() && nums[i] <= miss) {
        		miss += nums[i];
        		i++;
			}else {
				step++;
				miss += miss;
			}
        	
		}
		
		return step;
        
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
	
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->minPatches(nums, n);
	
	return 0;
	
}
