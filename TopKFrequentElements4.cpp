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
		
		kselection(rep, 0, rep.size() - 1, k);
		
		vector<int> result;
		
		for(int i = 0; i < k; i++) result.push_back(rep[i].first);
		
		return result;
    }
    
    void kselection(vector<pair<int, int> >& rep, int l, int r, int k) {
    	
    	if(l >= r) return;
    	int i = l, j = l;
    	pair<int, int> v = rep[r];
    		
		while(i < r) {
			if(rep[i].second > v.second) {
				swap(rep[i++], rep[j++]);
			}else {
				i++;
			}
		}
		swap(rep[j], rep[r]);
		int num = j - l + 1;
		if(num == k) return;
		else if(num > k) {
			kselection(rep, l, j - 1, k);
		}else {
			kselection(rep, j + 1, r, k - num);
		}
    	
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
