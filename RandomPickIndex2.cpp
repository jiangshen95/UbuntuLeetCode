#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
private:
	vector<int> nums;
public:
    Solution(vector<int> nums) {
        this->nums = nums;
    }
    
    int pick(int target) {
        int count = 0, res = -1;
        for(int i = 0; i < nums.size(); i++) {
        	if(nums[i] != target) continue;
        	count++;
        	if(rand() % count == 0) res = i;
//        	if(count == 0) {
//        		res = i;
//        		count++;
//			}else {
//				count++;
//				if(rand() % count == 0) res = i;
//			}
		}
		
		return res;
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
