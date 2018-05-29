#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    	int n = nums.size();
        vector<int> multi1(n, 1), multi2(n, 1);
		for(int i=1;i<n;i++){
			multi1[i] = nums[i - 1] * multi1[i - 1];
			multi2[n - i - 1] = nums[n - i] * multi2[n - i];
		}
		
		vector<int> result(n);
		for(int i=0;i<n;i++) {
			result[i] = multi1[i] * multi2[i];
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
