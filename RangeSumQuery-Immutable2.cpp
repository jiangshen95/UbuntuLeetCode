#include<iostream>
#include<vector>

using namespace std;

class NumArray {
private:
	vector<int> sums;
public:
    NumArray(vector<int> nums) {
    	int sum = 0;
        for(int i = 0;i < nums.size();i++) {
        	sum += nums[i];
        	sums.push_back(sum);
		}
    }
    
    int sumRange(int i, int j) {
        return i == 0 ? sums[j] : sums[j] - sums[i - 1];
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
