#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        
        int result = 0, mask = 0;
        for(int i = 31; i >= 0; i--) {
        	mask |= (1 << i);
        	unordered_set<int> s;
        	for(int num : nums) {
        		s.insert(mask & num);
			}
			
			// a ^ b = c  ==>  a = b ^ c 
			int t = result | (1 << i);
			for(auto n : s) {
				if(s.find(t ^ n) != s.end()) {
					result = t;
					break;
				}
			}
		}
		
		return result;
        
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
	
	Solution *solution = new Solution();
	cout<<solution->findMaximumXOR(nums);
	
	return 0;
	
}
