#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int> > findSubsequences(vector<int>& nums) {
        vector<vector<int> > result;
        vector<int> sequence;
        findSubSequence(result, nums, 0, sequence);
        return result;
    }
    
    void findSubSequence(vector<vector<int> >& result, vector<int>& nums, int pos, vector<int>& sequence) {
    	if(sequence.size() >= 2) result.push_back(sequence);
    	unordered_set<int> s;
    	for(int i = pos; i < nums.size(); i++) {
    		if(s.find(nums[i]) != s.end()) continue;
    		s.insert(nums[i]);
    		if(sequence.empty() || nums[i] >= sequence.back()) {
    			sequence.push_back(nums[i]);
    			findSubSequence(result, nums, i + 1, sequence);
    			sequence.pop_back();
			}
		}
	}
};

int main() {
	int n;
	cin>>n;
	
	vector<int> nums;
	for(int i = 0;i < n; i++) {
		int num;
		cin>>num;
		nums.push_back(num);
	}
	
	Solution *solution = new Solution();
	vector<vector<int> > result = solution->findSubsequences(nums);
	
	for(int i = 0; i < result.size(); i++) {
		for(int j = 0; j < result[i].size(); j++) cout<<result[i][j]<<"  ";
		cout<<endl;
	}
}
