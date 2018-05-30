#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int max = INT_MIN;
        vector<int> result;
        if(nums.size() == 0) return result;
        for(int i=0;i<k;i++){
        	if(nums[i] > max){
        		max = nums[i];
			}
		}
		
		result.push_back(max);
		
		for(int i=k;i<nums.size();i++) {
			if(nums[i] >= max){
				max = nums[i];
			}else if(nums[i - k] == max){
				max = nums[i - k + 1];
				for(int j = i - k + 1;j <= i;j++){
					if(nums[j] > max) max = nums[j];
				}
			}
			result.push_back(max);
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
	
	int k;
	cin>>k;
	
	Solution *solution = new Solution();
	vector<int> result = solution->maxSlidingWindow(nums, k);
	
	for(int i=0;i<result.size();i++){
		cout<<result[i]<<"  ";
	}
	
	return 0;
	
}
