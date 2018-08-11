#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class SegmentTreeNode {
public:
	int start, end;
	SegmentTreeNode *left;
	SegmentTreeNode *right;
	int sum;
	
	SegmentTreeNode(int start, int end) : start(start), end(end), left(NULL), right(NULL) {
		this->start = start;
		this->end = end;
		this->sum = 0;
	}
};

class NumArray {
private:
	SegmentTreeNode *root;
public:
    NumArray(vector<int> nums) {
    	if(nums.size() > 0) {
    		root = buildTree(nums, 0, nums.size() - 1);
		}
    }
    
    SegmentTreeNode* buildTree(vector<int> nums, int start, int end) {
    	if(start > end) {
    		return NULL; 
		}else {
			SegmentTreeNode *node = new SegmentTreeNode(start, end);
			if(start == end) {
				node->sum = nums[start];
			}else {
				int mid = start + (end - start) / 2;
				node->left = buildTree(nums, start, mid);
				node->right = buildTree(nums, mid + 1, end);
				node->sum = node->left->sum + node->right->sum;
			}
			return node;
		}
	}
    
    void update(int i, int val) {
        update(root, i, val);
    }
    
    void update(SegmentTreeNode *root, int i, int val) {
    	if(root->start == root->end) {
    		root->sum = val;
		}else {
			int mid = root->start + (root->end - root->start) / 2;
			if(i <= mid) {
				update(root->left, i, val);
			}else {
				update(root->right, i, val);
			}
			
			root->sum = root->left->sum + root->right->sum;
		}
	}
    
    int sumRange(int i, int j) {
        return sumRange(root, i, j);
    }
    
    int sumRange(SegmentTreeNode *root, int i, int j) {
    	if(root->start == i && root->end == j) {
    		return root->sum;
		}
		int mid = root->start + (root->end - root->start) / 2;
		if(i >= mid + 1) return sumRange(root->right, i, j);
		else if(j <= mid) return sumRange(root->left, i, j);
		else return sumRange(root->left, i, mid) + sumRange(root->right, mid + 1, j);
	}
};

int main() {
	
	int n;
	cin>>n;
	
	vector<int> nums;
	for(int i = 0;i < n;i++) {
		int num;
		cin>>num;
		nums.push_back(num);
	}
	
	NumArray *arr = new NumArray(nums);
	cout<<arr->sumRange(0, 2)<<endl;
	arr->update(1, 2);
	cout<<arr->sumRange(0, 2)<<endl;
	
	return 0;
	
}
