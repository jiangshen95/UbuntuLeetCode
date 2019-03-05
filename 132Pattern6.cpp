#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
    	stack<pair<int, int> > s;
    	for(int num : nums) {
    		if(s.empty() || num < s.top().first) s.push(make_pair(num, num));
    		else if(num > s.top().first){
    			auto last = s.top();
    			s.pop();
    			if(num < last.second) return true;
    			else {
    				last.second = num;
    				while(!s.empty() && num >= s.top().second) s.pop();
    				if(!s.empty() && s.top().first < num ) return true;
    				s.push(last);
				}
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
	solution->find132pattern(nums) ? cout<<"true" : cout<<"false";
	
	return 0;
	
}
