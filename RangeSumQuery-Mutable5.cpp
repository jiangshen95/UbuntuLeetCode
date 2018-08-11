#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class NumArray {
private:
	vector<int> bit;
	vector<int> nums;
	int n;
public:
    NumArray(vector<int> nums) {
        if(nums.size() > 0) {
        	this->nums = nums;
        	n = nums.size();
        	bit = vector<int>(n + 1);
        	for(int i = 0; i < n; i++) {
        		init(i, nums[i]);
			}
		}
    }
    
    void init(int i, int val) {
    	i ++;
    	while(i <= n) {
    		bit[i] += val;
    		i += (i & -i);
		}
	}
    
    
    void update(int i, int val) {
        
        int diff = val - nums[i];
        init(i, diff);
        nums[i] = val;
        
    }
    
    int getSum(int i) {
    	int sum = 0;
    	
    	i++;
    	while(i > 0) {
    		sum += bit[i];
    		i -= (i & -i);
		}
		
		return sum;
	}
    
    int sumRange(int i, int j) {
        return getSum(j) - getSum(i - 1);
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
