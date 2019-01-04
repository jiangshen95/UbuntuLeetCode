#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

//Ç°×ºÊ÷ 

class Solution {
public:
	
	struct TreeNode {
		vector<TreeNode*> next{NULL, NULL};
	};
	
    int findMaximumXOR(vector<int>& nums) {
        
        TreeNode *root = new TreeNode();
        for(int num : nums) {
        	TreeNode *cur = root;
        	for(int i = 31; i >= 0; i--) {
        		int t = (num >> i) & 1;
        		if(cur->next[t] == NULL) cur->next[t] = new TreeNode();
        		cur = cur->next[t];
			}
		}
        
        int result = 0;
        for(int num : nums) {
        	TreeNode *cur = root;
        	int temp = 0;
        	for(int i = 31; i >= 0; i--) {
        		int t = (num >> i) & 1;
        		if(cur->next[t ^ 1]) {
        			temp |= (1 << i);
        			cur = cur->next[t ^ 1];
				}else {
					cur = cur->next[t];
				}
			}
			result = max(result, temp);
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
	
	Solution *solution = new Solution();
	cout<<solution->findMaximumXOR(nums);
	
	return 0;
	
}
