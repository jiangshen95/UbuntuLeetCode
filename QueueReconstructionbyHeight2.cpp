#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<pair<int, int> > reconstructQueue(vector<pair<int, int> >& people) {
    	
    	sort(people.begin(), people.end(), [](const pair<int, int> a, const pair<int, int> b){
    		return a.first > b.first || (a.first == b.first && a.second < b.second);
		});
    	
        vector<pair<int, int> > result;
        
        for(auto p : people) result.insert(result.begin() + p.second, p);
		
		return result;
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
