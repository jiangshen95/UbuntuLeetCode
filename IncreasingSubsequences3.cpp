#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int> > findSubsequences(vector<int>& nums) {
        vector<vector<int> > result, cur(1);
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++) {
        	int n = cur.size();
        	int start = m[nums[i]];
        	m[nums[i]] = n;
        	for(int j = start; j < n; j++) {
        		if(cur[j].empty() || cur[j].back() <= nums[i]) {
        			cur.push_back(cur[j]);
        			cur.back().push_back(nums[i]);
        			if(cur.back().size() >= 2) result.push_back(cur.back());
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
