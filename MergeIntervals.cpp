#include<iostream>
#include<vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s,int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        
        interval_sort(intervals,0,intervals.size()-1);
        
        vector<Interval> result;
        
        if(intervals.size()>0){
            result.push_back(intervals[0]);
        }
        for(int i=1;i<intervals.size();i++){
            if(intervals[i].start<=result.back().end){
                if(intervals[i].end<=result.back().end){
                    continue;
                }else{
                    result[result.size()-1].end=intervals[i].end;
                }
                
            }else{
                result.push_back(intervals[i]);
            }
        }
        
        
        return result;
        
        /*int min_int=intervals[0].start,max_int=intervals[0].end;
        for(int i=1;i<intervals.size();i++){
            
            if(intervals[i].start<=max_int){
                min_int=min_int>intervals[i].start ? intervals[i].start : min_int;
                max_int=max_int>intervals[i].end ? max_int : intervals[i].end;
            }else{
                Interval temp=new Interval(min_int,max_int);
                result.push_back(temp);
                max_int=intervals[i].end;
            }
            
        }*/
    }
    
    void interval_sort(vector<Interval>& intervals,int l,int r){
        if(l<r){
            int i=l,j=r;
            int s=intervals[l].start,e=intervals[l].end;
            while(i<j){
                while(i<j&&intervals[j].start>=s) j--;
                intervals[i].start=intervals[j].start;
                intervals[i].end=intervals[j].end;
                while(i<j&&intervals[i].start<=s) i++;
                intervals[j].start=intervals[i].start;
                intervals[j].end=intervals[i].end;
            }
            intervals[i].start=s;
            intervals[i].end=e;
            interval_sort(intervals,l,i);
            interval_sort(intervals,i+1,r);
        }
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
    
    vector<Interval> result;
    Solution *solution=new Solution();
    result=solution->merge(intervals);
    
    for(int i=0;i<result.size();i++){
        cout<<result[i].start<<", "<<result[i].end<<endl;
    }
    
    return 0;
    
}
