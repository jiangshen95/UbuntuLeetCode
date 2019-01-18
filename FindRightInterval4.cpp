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
        vector<pair<int, int> > m;
        
        for(int i = 0; i < n; i++) m.push_back(make_pair(intervals[i].start, i));
    	
    	sort(m.begin(), m.end());
        
        vector<int> result;
        for(auto interval : intervals) {
        	int where = binarySearch(m, interval.end);
        	if(where < m.size()) result.push_back(m[where].second);
        	else result.push_back(-1);
		}
        return result;
    }
    
    int binarySearch(vector<pair<int, int> >& list, int val) {
    	int l = 0, r = list.size() - 1;
    	while(l <= r) {
    		int mid = (l + r) / 2;
    		if(list[mid].first >= val) r = mid - 1;
    		else l = mid + 1;
		}
		return l;
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
