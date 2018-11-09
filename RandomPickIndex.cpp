#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
private:
	unordered_map<int, vector<int> > m;
public:
    Solution(vector<int> nums) {
        for(int i = 0; i < nums.size(); i++) m[nums[i]].push_back(i);
    }
    
    int pick(int target) {
        int n = m[target].size();
        return m[target][rand() % n];
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
	
	Solution *solution = new Solution(nums);
	int p;
	cin>>p;
	cout<<solution->pick(p);
	
	return 0;
	
}
