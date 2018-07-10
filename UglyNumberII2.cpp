#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int nthUglyNumber(int n) {
        
        int i2 = 0, i3 = 0, i5 = 0;
        vector<int> nums(1, 1);
        
        while(nums.size() < n) {
        	int m2 = nums[i2] * 2;
        	int m3 = nums[i3] * 3;
        	int m5 = nums[i5] * 5;
        	int mn = min(m2, min(m3, m5));
        	if(mn == m2) i2 ++;
        	if(mn == m3) i3 ++;
        	if(mn == m5) i5 ++;
        	nums.push_back(mn);
		}
		
		return nums.back();
    }
};

int main() {
	
	int n;
	cin>>n;
	
	Solution *solution = new Solution();
	cout<<solution->nthUglyNumber(n);
	
	return 0; 
	
}
