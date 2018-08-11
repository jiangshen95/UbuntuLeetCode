#include<iostream>
#include<vector>

using namespace std;

class NumArray {
private:
	vector<int> nums;
	vector<int> sums;
public:
    NumArray(vector<int> nums) {
        this->nums = nums;
        sums = vector<int>(nums.size() + 1);
        for(int i = 0;i < nums.size();i++) {
        	sums[i + 1] = sums[i] + nums[i];
		}
    }
    
    void update(int i, int val) {
        int s = val - nums[i];
        if(i + 1 > sums.size() / 2) {
        	for(int j = i + 1;j < sums.size();j++) {
        		sums[j] += s;
			}
		}else {
			for(int j = 0;j < i + 1;j++) {
				sums[j] -= s;
			}
		}
		nums[i] = val;
    }
    
    int sumRange(int i, int j) {
        return sums[j + 1] - sums[i];
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
