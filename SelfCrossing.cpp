#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        vector<vector<int> > dic = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
        
        for(int i = 3; i < x.size(); i++) {
        	
        	if(x[i] >= x[i - 2] && x[i - 1] <= x[i - 3]) return true;
        	if(i == 4 && x[i - 1] == x[i - 3] && x[i] + x[i - 4] >= x[i - 2]) return true;
        	if(i >= 5 && x[i - 2] >= x[i - 4] && x[i - 2] - x[i] <= x[i - 4] && x[i - 1] <= x[i - 3] && x[i - 3] - x[i - 5] <= x[i - 1]) return true;
        	
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
	solution->isSelfCrossing(nums) ? cout<<"true" : cout<<"false";
	
	return 0;
	
}
