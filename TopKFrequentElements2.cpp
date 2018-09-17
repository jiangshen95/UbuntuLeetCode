#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int num : nums) m[num]++;
        priority_queue<pair<int, int> > q;
        for(auto& v : m) {
        	q.push(make_pair(v.second, v.first));
		}
		
		vector<int> result;
		
		for(int i = 0; i < k; i++) {
			result.push_back(q.top().second);
			q.pop();
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
