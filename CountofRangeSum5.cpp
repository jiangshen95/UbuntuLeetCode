#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
private:
	class BSTNode{
		public:
			long val;
			int count;
			int left_count;
			BSTNode *left;
			BSTNode *right;
			BSTNode(long val) : val(val), count(1), left_count(0), left(NULL), right(NULL) {}
	};
public:
	
	int getBound(BSTNode *root, long val, bool includeSelf) {
		if(root) cout<<"-------------"<<root->val<<"-------"<<val<<endl;
		if(root == NULL) return 0;
		if(root->val == val) return root->left_count + (includeSelf ? root->count : 0);
		else if(root->val > val) return getBound(root->left, val, includeSelf);
		else {
			cout<<"val: "<<root->val<<endl;
			if(root->right) cout<<"right: "<<root->right->val<<endl;
			cout<<"left_count: "<<root->left_count<<endl;
			return root->left_count + root->count + getBound(root->right, val, includeSelf);
		}
	}
	
	void insertNode(BSTNode *root, long x) {
		
		if(root->val == x) root->count++;
		else if(root->val < x) {
			if(root->right) insertNode(root->right, x);
			else root->right = new BSTNode(x);
		}else {
			root->left_count++;
			if(root->left) insertNode(root->left, x);
			else root->left = new BSTNode(x);
		}
		
	}
	
//	void insertNode(BSTNode*& root, long x) {
//		cout<<"x:"<<x<<endl;
//		if(root == NULL) {
//			cout<<"add node: "<<x<<endl;
//			root = new BSTNode(x);
//		}
//		else if(root->val == x) root->count++;
//		else if(root->val < x) {
//			cout<<"right: x"<<x<<endl;
//			insertNode(root->right, x);
//		}
//		else {
//			root->left_count++;
//			insertNode(root->left, x);
//		}
//	}
	
    int countRangeSum(vector<int>& nums, int lower, int upper) {
    	
    	BSTNode *root = new BSTNode(0);
    	
    	long sum = 0;
    	int count = 0;
    	for(int i = 0; i < nums.size(); i++) {
    		sum += nums[i];
    		count += getBound(root, sum - lower, true) - getBound(root, sum - upper, false);
    		//cout<<getBound(root, sum - lower, true)<<endl;
    		//cout<<getBound(root, sum - upper, false)<<endl;
    		//cout<<count<<endl;
    		insertNode(root, sum);
		}
    	
    	return count;
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
	
	int lower, upper;
	cin>>lower>>upper;
	
	Solution *solution = new Solution();
	cout<<solution->countRangeSum(nums, lower, upper);
	
	return 0;
	
}
