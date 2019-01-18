#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        
        int n = intervals.size();
        map<int, int> m;
        
        for(int i = 0; i < n; i++) m[intervals[i].start] = i;
        
        vector<int> result;
        for(auto interval : intervals) {
        	auto it = m.lower_bound(interval.end);
        	if(it == m.end()) result.push_back(-1);
        	else result.push_back(it->second);
		}
        return result;
    }
};

int main() {
	
	int n;
	cin>>n;
	
	vector<Interval> intervals;
	for(int i = 0; i < n; i++) {
		int s, e;
		cin>>s>>e;
		intervals.push_back(Interval(s, e));
	}
	
	Solution *solution = new Solution();
	vector<int> result = solution->findRightInterval(intervals);
	
	for(int i = 0; i < result.size(); i++) cout<<result[i]<<" ";
	
	return 0;
	
}
