/*
 * A Wrong Solution.
*/
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        long long average = 0;
        for(int num : nums) average += num;
        cout<<"average: "<<average<<endl;
        average /= (long long)nums.size();
        
        int left = 0, right = 0, left_max = INT_MIN, right_min = INT_MAX;
        for(int num : nums) {
        	if(num <= average) {
        		left++;
        		left_max = max(left_max, num);
			}else {
				right++;
				right_min = min(right_min, num);
			}
		}
		
		int target = left >= right ? left_max : right_min;
		
		cout<<"average: "<<average<<endl;
		cout<<"target: "<<target<<endl;
		
		long result = 0;
		for(int num : nums) result += (num >= target ? num - target : target - num);
		
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
	
	Solution *solution = new Solution();
	cout<<solution->minMoves2(nums);
	
	return 0;
	
}
