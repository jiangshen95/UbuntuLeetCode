#include<iostream>
#include<vector>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class SummaryRanges {
private:
	struct BSTNode {
		Interval interval;
		BSTNode *left;
		BSTNode *right;
		BSTNode(Interval interval) : interval(interval), left(NULL), right(NULL) {}
	};
	BSTNode *root;
	
	BSTNode* findMin(BSTNode *root) {
		if(root == NULL) return NULL;
		if(root->left == NULL) return root;
		return findMin(root->left);
	}
	
	BSTNode* findMax(BSTNode *root) {
		if(root == NULL) return NULL;
		if(root->right == NULL) return root;
		return findMax(root->right);
	}
	
	BSTNode* addNum(BSTNode *root, int val) {
		if(root == NULL) root = new BSTNode(Interval(val, val));
		else if(root->interval.start > val) {
			root->left = addNum(root->left, val);
		}else if(root->interval.end < val) {
			root->right = addNum(root->right, val);
		}
		return root;
	}
	
	BSTNode* findKey(BSTNode *root, int val) {
		if(root == NULL) return NULL;
		if(val > root->interval.end) return findKey(root->right, val);
		else if(val < root->interval.start) return findKey(root->left, val);
		return root;
	}
	
	BSTNode* remove(BSTNode *root, Interval interval) {
		if(root == NULL) return NULL;
		if(interval.start > root->interval.end) root->right = remove(root->right, interval);
		else if(interval.end < root->interval.start) root->left = remove(root->left, interval);
		else if(root->left != NULL && root->right != NULL) {
			root->interval = findMin(root->right)->interval;
			root->right = remove(root->right, root->interval);
		}else {
			root = (root->left == NULL ? root->right : root->left);
		}
		return root;
	}
	
	void inOrder(BSTNode *root, vector<Interval>& list) {
		if(root == NULL) return;
		inOrder(root->left, list);
		list.push_back(root->interval);
		inOrder(root->right, list);
	}
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
    	root = NULL;
    }
    
    void addNum(int val) {
        if(root == NULL) root = addNum(root, val);
        else {
        	if(findKey(root, val)) return;
        	BSTNode *left = findKey(root, val - 1);
        	BSTNode *right = findKey(root, val + 1);
			if(left == NULL && right == NULL) {
				root = addNum(root, val);
			}else if(left != NULL && right == NULL) {
				left->interval.end++;
			}else if(left == NULL && right != NULL) {
				right->interval.start--;
			}else {
				int e = right->interval.end;
				root = remove(root, right->interval);
				left->interval.end = e;
			}
		}
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> intervals;
        inOrder(root, intervals);
        return intervals;
    }
};

int main() {
	
	SummaryRanges *obj = new SummaryRanges();
	for(int i = 0; i < 5; i++) {
		int val;
		cin>>val;
		obj->addNum(val);
		vector<Interval> params = obj->getIntervals();
		for(int j = 0; j < params.size(); j++) {
			cout<<params[j].start<<"  "<<params[j].end<<endl;
		}
	}
	
	return 0;
	
}
