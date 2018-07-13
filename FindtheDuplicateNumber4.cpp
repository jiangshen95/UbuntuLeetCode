#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int n = nums.size() - 1, result = 0;
        for(int p=0;p<32;p++) {
        	int t = 1 << p;
        	int count1 = 0, count2 = 0;
        	for(int i=0;i<=n;i++) {
        		if(i != 0 && i & t) count1 ++;
				if(nums[i] & t) count2 ++; 
			}
			if(count2 > count1) result += t;
		}
        
        return result;
        
    }
};

int main() {
	
	int n;
	cin>>n;
	
	vector<int> nums;
	for(int i=0;i<n;i++) {
		int num;
		cin>>num;
		nums.push_back(num);
	}
	
	Solution *solution = new Solution();
	cout<<solution->findDuplicate(nums);
	
	return 0;
	
}
