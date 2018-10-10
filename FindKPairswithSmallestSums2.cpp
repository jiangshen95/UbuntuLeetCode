#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
public:
    vector<pair<int, int> > kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        
        vector<pair<int, int> > result;
        if(nums1.empty() || nums2.empty()) return result;
        
        auto comp = [&nums1, &nums2](pair<int, int> a, pair<int, int> b) {
        	return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
		};
		priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(comp)> min_heap(comp);
		
		min_heap.emplace(0, 0);
		
		while(k-- > 0 && !min_heap.empty()) {
			auto index_pair = min_heap.top();
			min_heap.pop();
			result.emplace_back(nums1[index_pair.first], nums2[index_pair.second]);
			if(index_pair.first + 1 < nums1.size()) min_heap.emplace(index_pair.first + 1, index_pair.second);
			if(index_pair.first == 0 && index_pair.second + 1 < nums2.size()) min_heap.emplace(index_pair.first, index_pair.second + 1);
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
