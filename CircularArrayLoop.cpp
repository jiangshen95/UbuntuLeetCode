#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
    	int n = nums.size();
        for(int i = 0; i < n; i++) {
        	if(nums[i] == 0) continue;
        	int k = i;
        	bool loop1_flag = false;
        	vector<bool> visited(n, false);
        	while(nums[k] != 0) {
        		int next = (k + nums[k]) % n;
        		if(next < 0) next += n;
        		cout<<"k: "<<k<<endl;
        		cout<<"next: "<<next<<endl;
        		if(k == next) loop1_flag = true;
        		if(nums[k] * nums[next] < 0) break;
        		nums[k] = 0;
        		visited[k] = true;
        		k = next;
			}
			if(!loop1_flag && nums[k] == 0 && visited[k]) return true;
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
	solution->circularArrayLoop(nums) ? cout<<"true" : cout<<"false";
	
	return 0;
	
}
