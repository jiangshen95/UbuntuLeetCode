#include<iostream>
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        unordered_map<long, unordered_map<long, int> > needDiffCount;
        unordered_multiset<int> s(A.begin(), A.end());
        
        int result = 0;
        for(int i = 1; i < A.size(); i++) {
        	if(needDiffCount.count(A[i])) {
        		for(auto& diffCount : needDiffCount[A[i]]) {
        			result += diffCount.second;
        			long need = A[i] + diffCount.first;
        			if(s.count(need)) {
        				needDiffCount[need][diffCount.first] += diffCount.second;
					}
				}
			}
			
			for(int j = 0; j < i; j++) {
				long diff = (long)A[i] - A[j];
				if(diff < INT_MIN || diff > INT_MAX) continue;
				long need = A[i] + diff;
				if(need < INT_MIN || need > INT_MAX || s.count(need) == 0) continue;
				needDiffCount[need][diff]++;
			}
			s.erase(s.find(A[i]));
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
	cout<<solution->numberOfArithmeticSlices(nums);
	
	return 0;
	
}
