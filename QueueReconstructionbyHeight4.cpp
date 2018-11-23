#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<pair<int, int> > reconstructQueue(vector<pair<int, int> >& people) {
    	
    	int n = people.size();
    	vector<int> tree(n + 1, 0);
    	
    	for(int i = 1; i <= n; i++) update(tree, i, 1);
    	
//    	sort(people.begin(), people.end(), [](const pair<int, int> a, const pair<int, int> b){
//    		return a.first > b.first || (a.first == b.first && a.second < b.second);
//		});
		sort(people.begin(), people.end());
    	
    	int pre = -1;
    	vector<int> preNum;
    	
    	vector<pair<int, int> > result(n);
    	
    	for(int i = 0; i < n; i++) {
    		if(people[i].first != pre) {
    			for(int j = 0; j < preNum.size(); j++) update(tree, preNum[j], -1);
    			preNum.clear();
			}
			int num = findKth(tree, people[i].second + 1);
			result[num - 1] = people[i];
			
			preNum.push_back(num);
			pre = people[i].first;
		}
		
		return result;
    }
    
    void update(vector<int>& tree, int index, int val) {
    	while(index < tree.size()) {
    		tree[index] += val;
    		index += index & (-index);
		}
	}
	
	int getSum(vector<int>& tree, int index) {
		int sum = 0;
		while(index > 0) {
			sum += tree[index];
			index -= index & (-index);
		}
		return sum;
	}
	
	int findKth(vector<int>& tree, int k) {
		int l = 1, r = tree.size() - 1;
		while(l <= r) {
			int mid = l + (r - l) / 2;
			if(getSum(tree, mid) >= k) r = mid - 1;
			else l = mid + 1;
		}
		
		return l;
	}
};

int main() {
	
	int n;
	cin>>n;
	
	vector<pair<int, int> > people;
	for(int i = 0; i < n; i++) {
		int h, k;
		cin>>h>>k;
		people.push_back(make_pair(h, k));
	}
	
	Solution *solution = new Solution();
	vector<pair<int, int> > result = solution->reconstructQueue(people);
	
	for(int i = 0; i < n; i++) {
		cout<<"["<<result[i].first<<","<<result[i].second<<"]"<<", ";
	}
	
	return 0;
}
