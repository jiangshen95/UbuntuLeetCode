#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    	unordered_map<int, int> m;
    	stack<int> st;
    	for(int num : nums2) {
			while(!st.empty() && st.top() < num) {
				m[st.top()] = num;
				st.pop();
			}
			st.push(num);
		}
		
		vector<int> result;
		for(int num : nums1) {
			result.push_back(m.count(num) ? m[num] : -1);
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
