#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class NumArray {
private:
	vector<int> b;
	vector<int> nums;
	int len;
public:
    NumArray(vector<int> nums) {
        this->nums = nums;
        double l = sqrt(nums.size());
        if(l == 0) return;
        len = ceil(nums.size() / l);
        b = vector<int>(len);
        for(int i = 0;i < nums.size();i++) {
        	b[i / len] += nums[i];
		}
    }
    
    void update(int i, int val) {
        b[i / len] += val - nums[i];
		nums[i] = val;
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        int start = i / len, end = j / len;
        if(start == end) {
        	for(int k = i;k <= j;k++) sum += nums[k];
		}else {
			for(int k = start + 1;k < end;k++) sum += b[k];
			for(int k = i;k < (start + 1) * len;k++) sum += nums[k];
			for(int k = end * len;k <= j;k++) sum += nums[k];
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
