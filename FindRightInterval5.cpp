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
private:
	struct Point {
		int val;
		int flag;
		int index;
		Point(int val, int flag, int index) : val(val), flag(flag), index(index) {}
	}; 
public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
        
        vector<Point> points;
		for(int i = 0; i < intervals.size(); i++) {
			points.push_back(Point(intervals[i].start, 0, i));
			points.push_back(Point(intervals[i].end, 1, i));
		} 
		
		sort(points.begin(), points.end(), [](Point a, Point b) {
			if(a.val != b.val) return a.val < b.val;
			else return a.flag > b.flag;
		});
		
		vector<int> preIndexs;
		vector<int> result(intervals.size(), -1);
		for(auto point : points) {
			if(point.flag == 0) {
				for(int i : preIndexs) {
					result[i] = point.index;
				}
				preIndexs.clear();
			}else {
				preIndexs.push_back(point.index);
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
