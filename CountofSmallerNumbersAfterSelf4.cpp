#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
    	
    	int n = nums.size();
    	vector<int> nums2(n);
    	
    	if(n == 0) return nums2;
    	
    	int max_num = INT_MIN;
    	int min_num = INT_MAX;
    	
    	for(int i = 0; i < n; i++) {
    		min_num = min(min_num, nums[i]);
		}
		
		for(int i = 0; i < n; i++) {
			nums2[i] = nums[i] - min_num + 1;
			max_num = max(max_num, nums2[i]);
		}
		
		vector<int> tree(max_num + 1);
		vector<int> counts(n);
		for(int i = n - 1; i >= 0; i--) {
			counts[i] = getCount(tree, nums2[i] - 1);
			update(tree, nums2[i]);
		}
		
		return counts;
    }
    
    int getCount(vector<int> tree, int i) {
    	int count = 0;
    	while(i > 0) {
    		count += tree[i];
    		i -= (i & -i);
		}
		return count;
	}
    
    void update(vector<int>& tree, int i) {
    	while(i < tree.size()) {
    		tree[i]++;
    		i += (i & -i);
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
	vector<int> counts = solution->countSmaller(nums);
	
	for(int i = 0; i < counts.size(); i++) cout<<counts[i]<<"  ";
	
	return 0;
	
}
