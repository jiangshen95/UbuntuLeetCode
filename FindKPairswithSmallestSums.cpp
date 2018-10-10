#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<pair<int, int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<pair<int, int> > result;
        
        if(nums1.empty() || nums2.empty()) return result;
        
        int n1 = nums1.size(), n2 = nums2.size();
        
        vector<int> index(n1, 0);
        
        for(int i = 0; i < k; i++) {
        	
        	int min_sum = INT_MAX;
        	int min_index = -1;
        	for(int j = 0; j < n1; j++) {
        		if(index[j] < n2 && nums1[j] + nums2[index[j]] < min_sum) {
        			min_sum = nums1[j] + nums2[index[j]];
        			min_index = j;
				}
			}
			if(min_index == -1) break;
			result.push_back(make_pair(nums1[min_index], nums2[index[min_index]]));
			index[min_index]++;
			
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
	
	int k;
	cin>>k;
	
	Solution *solution = new Solution();
	vector<pair<int, int> > result = solution->kSmallestPairs(nums1, nums2, k);
	
	for(int i = 0; i < result.size(); i++) {
		cout<<result[i].first<<"  "<<result[i].second<<endl;
	}
	
	return 0;
}
