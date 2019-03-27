#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size() <= 3) return false;
        int sum = 0;
        for(int num : nums) sum += num;
        if(sum % 4) return false;
        vector<bool> visited(nums.size(), false);
        int len = sum / 4;
        cout<<"len: "<<len<<endl;
        return makeSide(len, 0, 1, 0, nums, visited);
    }
    
    bool makeSide(int len, int total, int count, int pos, vector<int>& nums, vector<bool>& visited) {
    	if(total == len) {
    		for(int i = 0; i < visited.size(); i++) cout<<visited[i]<<" ";
    		cout<<endl;
    		if(count == 4) return true;
    		if(makeSide(len, 0, count + 1, 0, nums, visited)) return true;
    		return false;
		}
    	for(int i = pos; i < nums.size(); i++) {
    		if(!visited[i] && total + nums[i] <= len) {
    			visited[i] = true;
    			if(makeSide(len, total + nums[i], count, i + 1, nums, visited)) return true;
    			visited[i] = false;
			}
		}
		return false;
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
	solution->makesquare(nums) ? cout<<"true" : cout<<"false";
	
	return 0;
}
