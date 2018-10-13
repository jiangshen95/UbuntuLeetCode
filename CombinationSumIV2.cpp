/*
** Time Limit Exceeded
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
    	int sum = 0;
    	vector<int> stack;
    	stack.push_back(0);
    	int count = 0;
    	while(!stack.empty()) {
    		int index = stack.back();
    		sum += nums[index];
    		
//    		for(int i = 0; i < stack.size(); i++) cout<<stack[i]<<"  ";
//    		cout<<endl;
//    		cout<<sum<<endl<<endl;
    		
    		if(sum < target) {
    			stack.push_back(index);
//    			stack.push_back(0);
			}else {
				if(sum == target) count++;
				stack.pop_back();
				sum -= nums[index];
				
				while(index + 1 >= nums.size() && !stack.empty()) {
					index = stack.back();
					stack.pop_back();
					sum -= nums[index];
				}
				
				if(index + 1 < nums.size()) {
					stack.push_back(index + 1);
				}
				
			}
    		
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
	
	int target;
	cin>>target;
	
	Solution *solution = new Solution();
	cout<<solution->combinationSum4(nums, target);
	
	return 0;
	
}
