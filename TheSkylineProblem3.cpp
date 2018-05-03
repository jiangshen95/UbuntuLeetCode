#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
public:
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        
        vector<pair<int, int> > result;
        
        priority_queue<pair<int, int> > livebuilding;
        int cur = 0, cur_x = 0, cur_h = 0;
        while(cur < buildings.size() || !livebuilding.empty()){
            cur_x = livebuilding.empty() ? buildings[cur][0] : livebuilding.top().second;
            if(cur >= buildings.size() || buildings[cur][0] > cur_x){
                while(!livebuilding.empty() && (livebuilding.top().second <= cur_x)){
                    livebuilding.pop();
                }
            }else{
                cur_x = buildings[cur][0];
                while(cur < buildings.size() && buildings[cur][0] == cur_x){
                    livebuilding.push({buildings[cur][2], buildings[cur][1]});
                    cur ++;
                }
            }
            cur_h = livebuilding.empty() ? 0 : livebuilding.top().first;
            
            if(result.empty() || (result.back().second != cur_h)) result.push_back({cur_x, cur_h});
        }
        
        return result;
    }
};

int main(){
    
    int n;
    cin>>n;
    
    vector<vector<int> > buildings;
    for(int i=0;i<n;i++){
        vector<int> building;
        int l, r, h;
        cin>>l>>r>>h;
        building.push_back(l);
        building.push_back(r);
        building.push_back(h);
        buildings.push_back(building);
    }
    
    Solution *solution = new Solution();
    vector<pair<int, int> > skyline = solution->getSkyline(buildings);
    for(int i=0;i<skyline.size();i++){
        cout<<skyline[i].first<<", "<<skyline[i].second<<endl;
    }
    
    return 0;
    
}

