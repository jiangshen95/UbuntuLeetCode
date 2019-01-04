#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        
        unordered_set<int> set0, set1;
        int maxValue = 0, i;
        for(i = 31; i >= 0; i--) {
        	for(int num : nums) {
        		if((num & (1 << i)) == 0) set0.insert(num);
        		else set1.insert(num);
			}
			if(!set0.empty() && !set1.empty()) {
				maxValue = (1 << i);
				break;
			}else {
				set0.clear();
				set1.clear();
			}
		}
		
		return maxValue + getMaxXor(set0, set1, i - 1);
        
    }
    
    int getMaxXor(unordered_set<int>& set0, unordered_set<int>& set1, int pos) {
    	if(set0.empty() || set1.empty() || pos < 0) return 0;
    	
    	unordered_set<int> set00, set01, set10, set11;
    	
    	for(int n : set0) {
    		if((n & (1 << pos)) > 0) set01.insert(n);
    		else set00.insert(n);
		}
		
		for(int n : set1) {
			if((n & (1 << pos)) > 0) set11.insert(n);
			else set10.insert(n);
		} 
		
		if(set00.empty() && set10.empty()) return getMaxXor(set0, set1, pos - 1);
		else if(set01.empty() && set11.empty()) return getMaxXor(set0, set1, pos - 1);
		else {
			int maxValue1 = getMaxXor(set00, set11, pos - 1);
			int maxValue2 = getMaxXor(set01, set10, pos - 1);
			return (1 << pos) + max(maxValue1, maxValue2);
		}
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
