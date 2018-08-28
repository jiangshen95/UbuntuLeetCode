#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
    	
    	vector<int> temp = nums;
    	
    	sort(temp.begin(), temp.end());
    	
    	int n = nums.size();
    	int i = (n + 1) / 2, j = n;
    	for(int k = 0; k < n; k++) {
    		nums[k] = k & 1 ? temp[--j] : temp[--i];
		}
    	
        
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
	solution->wiggleSort(nums);
	
	for(int i = 0; i < n; i++) cout<<nums[i]<<"  ";
	
	return 0;
	
}
