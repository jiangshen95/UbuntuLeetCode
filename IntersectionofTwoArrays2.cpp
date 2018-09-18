#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    	
    	unordered_map<int, int> m;
    	for(int num : nums1) m[num]++;
    	
    	vector<int> result;
    	for(int num : nums2) {
    		if(m[num]) {
    			result.push_back(num);
    			m[num] = 0;
			}
		}
		
		return result;
    }
};

int main() {
	
	int n;
	cin>>n;
	
	vector<int> nums1;
	for(int i = 0; i < n; i++) {
		int num;
		cin>>num;
		nums1.push_back(num);
	}
	
	cin>>n;
	vector<int> nums2;
	for(int i = 0; i < n; i++) {
		int num;
		cin>>num;
		nums2.push_back(num);
	}
	
	Solution *solution = new Solution();
	vector<int> result = solution->intersection(nums1, nums2);
	
	for(int i = 0; i < result.size(); i++) cout<<result[i]<<"  ";
	
	return 0;
	
}
