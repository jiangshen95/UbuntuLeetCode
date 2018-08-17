#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
    	
        int n = nums.size();
        vector<int> counts(n);
        
        for(int i = n - 1; i >= 0; i--) {
        	int t = i;
        	for(int j = i + 1; j < n; j++) {
        		if(nums[j] >= nums[t]) {
        			int x = nums[j];
        			nums[j] = nums[t];
        			nums[t] = x;
        			t = j;
				}else {
					counts[i] = n - j;
					break;
				}
			}
        	
		}
		
		return counts;
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
	vector<int> counts = solution->countSmaller(nums);
	
	for(int i = 0; i < counts.size(); i++) cout<<counts[i]<<"  ";
	
	return 0;
	
}
