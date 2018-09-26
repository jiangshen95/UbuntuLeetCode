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

class SummaryRanges {
private:
	vector<Interval> intervals;
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
    }
    
    void addNum(int val) {
        auto Cmp = [](Interval a, Interval b) {return a.start < b.start;};
        auto it = lower_bound(intervals.begin(), intervals.end(), Interval(val, val), Cmp);
        int s = val, e = val;
        if(it != intervals.begin() && (it - 1)->end + 1 >= val) it--;
        while(it != intervals.end() && val + 1 >= it->start && val - 1 <= it->end) {
        	s = min(s, it->start);
        	e = max(e, it->end);
        	it = intervals.erase(it);
		}
		intervals.insert(it, Interval(s, e));
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
