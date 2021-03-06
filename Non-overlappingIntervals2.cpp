#include<iostream>
#include<vector>
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
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b){
        	return a.end < b.end;
		});
		
		int end = INT_MIN;
		int count = 0;
		for(auto interval : intervals) {
			if(interval.start >= end) end = interval.end;
			else count++;
		}
		
		return count;
        
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
	cout<<solution->eraseOverlapIntervals(intervals);
	
	return 0;
	
}
