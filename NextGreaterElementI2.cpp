#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    	unordered_map<int, int> m;
    	for(int i = 0; i < nums2.size(); i++) m[nums2[i]] = i;
    	
    	vector<int> result(nums1.size(), -1);
    	for(int i = 0; i < nums1.size(); i++) {
    		for(int j = m[nums1[i]] + 1; j < nums2.size(); j++) {
    			if(nums2[j] > nums1[i]) {
    				result[i] = nums2[j];
    				break;
				}
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
	vector<int> result = solution->nextGreaterElement(nums1, nums2);
	for(int num : result) cout<<num<<" ";
	
	return 0;
}
