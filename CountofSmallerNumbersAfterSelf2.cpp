#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
	struct Node {
		Node *left, *right;
		int val, sum, dup;
		Node(int val, int sum) : val(val), sum(sum), dup(1), left(NULL), right(NULL) {
		}
	};
    vector<int> countSmaller(vector<int>& nums) {
    	
    	int n = nums.size();
    	vector<int> counts(n);
    	
        Node *root = NULL;
        for(int i = n - 1; i >= 0; i--) {
        	root = insert(counts, root, i, nums[i], 0); 
		}
		
		return counts;
    }
    
    Node* insert(vector<int>& counts, Node *node, int i, int num, int preSum) {
    	if(node == NULL) {
    		node = new Node(num, 0);
    		counts[i] = preSum;
		}else if(node->val == num) {
			node->dup++;
			counts[i] = node->sum + preSum;
		}else if(node->val > num) {
			node->sum++;
			node->left = insert(counts, node->left, i, num, preSum);
		}else {
			node->right = insert(counts, node->right, i, num, node->sum + preSum + node->dup);
		}
		
		return node;
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
