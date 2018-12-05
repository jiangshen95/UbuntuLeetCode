#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s;
        for(int num : nums) {
        	s.insert(num);
        	if(s.size() > 3) s.erase(s.begin());
		}
		
		return s.size() == 3 ? *s.begin() : *s.rbegin();
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
	cout<<solution->thirdMax(nums);
	
	return 0;
	
}
