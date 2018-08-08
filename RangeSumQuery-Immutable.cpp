#include<iostream>
#include<vector>

using namespace std;

class NumArray {
private:
	vector<int> nums; 
public:
    NumArray(vector<int> nums) {
        this->nums = nums;
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        for(int k = i;k <= j;k++) sum += nums[k];
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
	cout<<arr->sumRange(2, 5)<<endl;
	cout<<arr->sumRange(0, 5)<<endl;
	
	return 0; 
}
