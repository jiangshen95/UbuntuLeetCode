#include<iostream>
#include<vector>

using namespace std;

struct Interval{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e): start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        
        vector<Interval> result;
        
        int i=0;
        while(i<intervals.size()&&intervals[i].end<newInterval.start){
            result.push_back(intervals[i++]);
        }
        
        while(i<intervals.size()&&intervals[i].start<=newInterval.end){
            newInterval=Interval(intervals[i].start>newInterval.start ? newInterval.start: intervals[i].start,
                                intervals[i].end>newInterval.end ? intervals[i].end: newInterval.end);
            i++;
        }
        
        result.push_back(newInterval);
        
        while(i<intervals.size()){
            result.push_back(intervals[i++]);
        }
        
        return result;
        
    }
};

int main(){
    int n;
    cin>>n;
    
    vector<Interval> intervals;
    for(int i=0;i<n;i++){
        int start,end;
        cin>>start>>end;
        Interval interval(start,end);
        intervals.push_back(interval);
    }
    
    int s,e;
    cin>>s>>e;
    Interval newInterval(s,e);
    
    vector<Interval> result;
    Solution *solution=new Solution();
    result=solution->insert(intervals, newInterval);
    
    for(int i=0;i<result.size();i++){
        cout<<result[i].start<<", "<<result[i].end<<endl;
    }
    
    return 0;
}

