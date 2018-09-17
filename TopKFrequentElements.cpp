#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int num : nums) m[num]++;
        vector<pair<int, int> > rep;
        for(auto& v : m) {
        	rep.push_back(make_pair(v.first, v.second));
		}
		
		qsort(rep, 0, rep.size() - 1);
		
		vector<int> result;
		
		for(int i = 0; i < k; i++) result.push_back(rep[i].first);
		
		return result;
    }
    
    void qsort(vector<pair<int, int> >& rep, int l, int r) {
    	if(l >= r) return;
    	pair<int, int> v = rep[l];
    	int i = l, j = r;
    	while(i < j) {
    		while(i < j && rep[j].second <= v.second) j--;
    		rep[i] = rep[j];
    		while(i < j && rep[i].second >= v.second) i++;
    		rep[j] = rep[i];
		}
		rep[i] = v;
		qsort(rep, l, i);
		qsort(rep, i + 1, r);
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
	
	int k;
	cin>>k;
	
	Solution *solution = new Solution();
	vector<int> result = solution->topKFrequent(nums, k);
	
	for(int i = 0; i < result.size(); i++) {
		cout<<result[i]<<"  ";
	}
	
	return 0;
	
} 
