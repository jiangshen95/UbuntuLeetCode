#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> readBinaryWatch(int num) {
    	
    	vector<string> result;
    	
    	vector<int> hours = {1, 2, 4, 8};
		vector<int> minutes = {1, 2, 4, 8, 16, 32};
    	
        for(int i = 0; i < 4; i++) {
        	if(num - i < 6 && num - i >= 0) {
        		vector<int> all_hours = getTimes(i, hours);
        		vector<int> all_minutes = getTimes(num - i, minutes);
        		
        		for(int h : all_hours) {
        			for(int m : all_minutes) {
        				string s = to_string(h);
        				s += ":";
        				if(m / 10 == 0) s += "0";
        				s += to_string(m);
        				result.push_back(s);
					}
				}
			}
		}
		
		return result;
    }
    
    vector<int> getTimes(int num, vector<int> nums) {
    	vector<int> result;
    	getTimes(num, 0, nums, 0, result);
    	return result;
	}
	
	void getTimes(int count, int index, vector<int> nums, int sum, vector<int>& result) {
		if(count == 0) {
			if((nums.size() == 4 && sum < 12) || (nums.size() == 6 && sum < 60))
				result.push_back(sum);
			return;
		}
		for(int i = index; i < nums.size(); i++) {
			getTimes(count - 1, i + 1, nums, sum + nums[i], result);
		}
	}
    
};

int main() {
	
	int num;
	cin>>num;
	
	Solution *solution = new Solution();
	vector<string> result = solution->readBinaryWatch(num);
	
	for(int i = 0; i < result.size(); i++) cout<<result[i]<<"  ";
	cout<<endl;
	
	return 0;
	
}
