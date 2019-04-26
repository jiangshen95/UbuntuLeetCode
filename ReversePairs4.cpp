/*
 * Time Limit Exceeded
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
private:
	struct Node {
		Node *left, *right;
		int val;
		int count_ge;
		Node(int val) : val(val), left(NULL), right(NULL), count_ge(1) {}
	};
public:
    int reversePairs(vector<int>& nums) {
        Node *head = NULL;
        int result = 0;
        for(int i = 0; i < nums.size(); i++) {
        	result += search(head, (long long)nums[i] * 2 + 1);
        	head = insert(head, nums[i]);
		}
		return result;
    }
    
    int search(Node *head, long long target) {
    	if(head == NULL) return 0;
    	else if(target == head->val) return head->count_ge;
    	else if(target > head->val) return search(head->right, target);
    	else return head->count_ge + search(head->left, target);
	}
	
	Node* insert(Node *head, int val) {
		if(head == NULL) return new Node(val);
		if(val == head->val) head->count_ge++;
		else if(val > head->val) {
			head->count_ge++;
			head->right = insert(head->right, val);
		}
		else {
			head->left = insert(head->left, val);
		}
		return head;
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
	cout<<solution->reversePairs(nums);
	
	return 0;
}
