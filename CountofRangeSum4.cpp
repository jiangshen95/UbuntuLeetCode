#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

class Solution {
private:
	class SegmentTree {
	public:
		SegmentTree *left;
		SegmentTree *right;
		long l, r;
		int count;
		SegmentTree(long l, long r) : l(l), r(r), count(0), left(NULL), right(NULL) {}
	};
public:
	
	SegmentTree* buildSegmentTree(vector<long> sums, int l, int r) {
		if(l > r) return NULL;
		SegmentTree *root = new SegmentTree(sums[l], sums[r]);
		if(l == r) return root;
		long m = l + (r - l) /2;
		root->left = buildSegmentTree(sums, l, m);
		root->right = buildSegmentTree(sums, m + 1, r);
		return root;
	}
	
	int getCount(SegmentTree *root, long lower, long upper) {
		if(root == NULL) return 0;
		if(root->r < lower || root->l > upper) return 0;
		if(root->l >= lower && root->r <= upper) {
			return root->count;
		}else {
			return getCount(root->left, lower, upper) + getCount(root->right, lower, upper);
		}
		
	}
	
	void updateSegmentTree(SegmentTree *root, int num) {
		if(root == NULL) return;
		if(root->l <= num && root->r >= num) {
			root->count++;
			updateSegmentTree(root->left, num);
			updateSegmentTree(root->right, num);
		}
	}
	
    int countRangeSum(vector<int>& nums, int lower, int upper) {
    	
    	set<long> sum_set;
    	long sum = 0;
    	for(int i = 0; i < nums.size(); i++) {
    		sum += nums[i];
    		sum_set.insert(sum);
		} 
		
		vector<long> sums(sum_set.begin(), sum_set.end());
		
		sort(sums.begin(), sums.end());
		
		SegmentTree *root = buildSegmentTree(sums, 0, sums.size() - 1);
		
		int count = 0;
		for(int i = nums.size() - 1; i >= 0; i--) {
			updateSegmentTree(root, sum);
			sum -= nums[i];
			count += getCount(root, sum + lower, sum + upper);
			
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
