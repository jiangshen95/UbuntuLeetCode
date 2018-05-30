#include<iostream>
#include<vector>
#include<limits.h>
#include<deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        if(nums.size() == 0 || k <= 0) return result;
        
        deque<int> q;
        
        for(int i=0;i<nums.size();i++) {
        	while(!q.empty() && q.front() < i - k + 1){
        		q.pop_front();
			}
			while(!q.empty() && nums[q.back()] < nums[i]) {
				q.pop_back();
			}
			q.push_back(i);
			if(i >= k - 1) result.push_back(nums[q.front()]);
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
