#include<iostream>
#include<vector>
#include<unordered_map>
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
        
        unordered_map<int, int> m;
        for(int i = 0; i < n; i++) m[intervals[i].start] = i;
        
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {
        	return a.start < b.start;
		});
        
        vector<int> result(n, -1);
        
        for(int i = 0; i < n; i++) {
        	for(int j = i + 1; j < n; j++) {
        		if(intervals[j].start >= intervals[i].end) {
        			result[m[intervals[i].start]] = m[intervals[j].start];
        			break;
				}
			}
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
