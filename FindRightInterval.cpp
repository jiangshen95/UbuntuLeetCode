#include<iostream>
#include<vector>

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
        vector<int> result(n, 0);
        
        for(int i = 0; i < n; i++) {
        	int min_start = INT_MAX, index = -1;
        	for(int j = 0; j < n; j++) {
        		if(intervals[j].start >= intervals[i].end) {
        			if(intervals[j].start < min_start) {
        				min_start = intervals[j].start;
        				index = j;
					}
				}
			}
			result[i] = index;
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
