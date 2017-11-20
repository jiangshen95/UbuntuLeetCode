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
        
        int start_in=0, end_in=0;
        vector<Interval> result;
        
        if(intervals.empty()){
            result.push_back(newInterval);
            return result;
        }
        
        
        for(int i=0;i<intervals.size()-1;i++){
            if(intervals[i].start<=newInterval.start&&intervals[i+1].start>=newInterval.start){
                start_in=i;
            }
            if(intervals[i].end<=newInterval.end&&intervals[i+1].end>=newInterval.end){
                end_in=i;
            }
        }
        if(intervals.back().start<=newInterval.start){
            start_in=intervals.size()-1;
        }else if(intervals.front().start>=newInterval.start){
            start_in--;
        }
        if(intervals.back().end<=newInterval.end){
            end_in=intervals.size()-1;
        }else if(intervals.front().end>=newInterval.end){
            end_in--;
        }
        
        for(int i=0;i<start_in;i++){
            result.push_back(intervals[i]);
        }
        
        if((start_in>=0&&intervals[start_in].end<newInterval.start) || start_in<0){
            if(start_in>=0){
                result.push_back(intervals[start_in]);
            }
            
            if((end_in+1<intervals.size()&&newInterval.end<intervals[end_in+1].start) || end_in+1>=intervals.size()){
                result.push_back(newInterval);
            }else{
                if(end_in+1<intervals.size()){
                    result.push_back(Interval(newInterval.start, intervals[end_in+1].end));
                    end_in++;
                }
            }
            
        }else{
            if((end_in+1<intervals.size()&&newInterval.end<intervals[end_in+1].start) || end_in+1>=intervals.size()){
                result.push_back(Interval(intervals[start_in].start, newInterval.end));
            }else{
                if(end_in+1<intervals.size()){
                    result.push_back(Interval(intervals[start_in].start, intervals[end_in+1].end));
                    end_in++;
                }
            }
        }
        
        for(int i=end_in+1;i<intervals.size();i++){
            result.push_back(intervals[i]);
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
