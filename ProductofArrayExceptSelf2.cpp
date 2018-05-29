#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    	int n = nums.size();
        vector<int> result(n, 1);
        int temp = 1;
		for(int i=1;i<n;i++){
			temp *= nums[i - 1];
			result[i] *= temp;
		}
		
		temp = 1;
		for(int i=n-2;i>=0;i--){
			temp *= nums[i + 1];
			result[i] *= temp;
		}
		
		return result;
    }
};

int main() {
	int n;
	cin>>n;
	
	vector<int> nums;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		nums.push_back(num);
	}
	
	Solution *solution = new Solution();
	vector<int> result = solution->productExceptSelf(nums);
	
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<"  ";
	}
	
	return 0;
}
