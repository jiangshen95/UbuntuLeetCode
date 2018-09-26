#include<iostream>
#include<vector>

using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

class SummaryRanges {
private:
	vector<Interval> intervals;
	
	int binarySearch(vector<Interval> intervals, int l, int r, int val) {
		int mid;
		while(l <= r) {
			mid = l + (r - l) / 2;
			if(intervals[mid].end < val) l = mid + 1;
			else if(intervals[mid].start > val) r = mid - 1;
			else return mid;
		}
		return r;
	}
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
    }
    
    void addNum(int val) {
        if(intervals.empty()) intervals.push_back(Interval(val, val));
        else {
        	int index = binarySearch(intervals, 0, intervals.size() - 1, val);
        	if(index == -1) {
        		if(val == intervals[0].start - 1) intervals[0].start--;
        		else if(val < intervals[0].start) intervals.insert(intervals.begin(), Interval(val, val));
			}else if(index == intervals.size() - 1) {
				if(val == intervals.back().end + 1) intervals[intervals.size() - 1].end++;
				else if(val > intervals.back().end) intervals.push_back(Interval(val, val));
			}else {
				if(val == intervals[index].end + 1 && val == intervals[index + 1].start - 1) {
					intervals[index].end = intervals[index + 1].end;
					intervals.erase(intervals.begin() + index + 1);
				}else if(val == intervals[index].end + 1) intervals[index].end++;
				else if(val == intervals[index + 1].start - 1) intervals[index + 1].start--;
				else if(val > intervals[index].end && val < intervals[index + 1].start) intervals.insert(intervals.begin() + index + 1, Interval(val, val));
			}
		}
    }
    
    vector<Interval> getIntervals() {
        return this->intervals;
    }
};

int main() {
	
	SummaryRanges *obj = new SummaryRanges();
	for(int i = 0; i < 5; i++) {
		int val;
		cin>>val;
		obj->addNum(val);
		vector<Interval> params = obj->getIntervals();
		for(int j = 0; j < params.size(); j++) {
			cout<<params[j].start<<"  "<<params[j].end<<endl;
		}
	}
	
	return 0;
	
}
