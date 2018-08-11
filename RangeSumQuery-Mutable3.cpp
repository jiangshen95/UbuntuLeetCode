#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class NumArray {
private:
	vector<int> tree;
	int n;
public:
    NumArray(vector<int> nums) {
        if(nums.size() > 0) {
        	n = nums.size();
        	tree = vector<int>(2 * n);
        	buildTree(nums);
		}
    }
    
    void buildTree(vector<int> nums) {
    	for(int i = 0, j = n;j < tree.size();j++, i++) {
    		tree[j] = nums[i];
		}
		
		for(int i = n - 1; i > 0; i--) {
			tree[i] = tree[i * 2] + tree[i * 2 + 1];
		}
	}
    
    void update(int i, int val) {
        
        int t = i + n;
        tree[t] = val;
        t /= 2;
        for(; t > 0; t /= 2) {
        	tree[t] = tree[t * 2] + tree[t * 2 + 1];
		}
        
    }
    
    int sumRange(int i, int j) {
        int l = i + n;
        int r = j + n;
        int sum = 0;
        while(l <= r) {
        	if(l % 2 == 1) {
        		sum += tree[l];
        		l++;
			}
			if(r % 2 == 0) {
				sum += tree[r];
				r--;
			}
			l /= 2;
			r /= 2;
		}
		return sum;
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
