#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    	
    	sort(nums1.begin(), nums1.end());
    	sort(nums2.begin(), nums2.end());
    	
    	vector<int> result;
    	
    	int i = 0, j = 0;
    	while(i < nums1.size() && j < nums2.size()) {
    		if(i > 0 && nums1[i] == nums1[i - 1]) {
    			i++;
    			continue;
			}
			if(j > 0 && nums2[j] == nums2[j - 1]) {
				j++;
				continue;
			}
    		if(nums1[i] < nums2[j]) i++;
    		else if(nums1[i] > nums2[j]) j++;
    		else {
    			result.push_back(nums1[i]);
    			i++;
    			j++;
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
