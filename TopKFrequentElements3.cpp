#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int num : nums) m[num]++;
        vector<vector<int> > bucket(nums.size() + 1);
        for(auto& v : m) {
        	bucket[v.second].push_back(v.first);
		}
		
		vector<int> result;
		
		for(int i = nums.size(); i > 0; i--) {
			for(int j = 0; j < bucket[i].size(); j++) {
				result.push_back(bucket[i][j]);
				if(result.size() == k) return result;
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
	
	int k;
	cin>>k;
	
	Solution *solution = new Solution();
	vector<int> result = solution->topKFrequent(nums, k);
	
	for(int i = 0; i < result.size(); i++) {
		cout<<result[i]<<"  ";
	}
	
	return 0;
	
} 
