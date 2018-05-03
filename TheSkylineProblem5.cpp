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
        int x = 0, h = 0, n = buildings.size();
        int i = 0;
        while(i < n || !livebuilding.empty()){
            
            if(livebuilding.empty() || (i < n && livebuilding.top().second >= buildings[i][0])){
                x = buildings[i][0];
                while(i < n && buildings[i][0] == x){
                    livebuilding.push({buildings[i][2], buildings[i][1]});
                    i ++;
                }
            }else{
                x = livebuilding.top().second;
                while(!livebuilding.empty() && livebuilding.top().second <= x)
                    livebuilding.pop();
            }
            
            h = livebuilding.empty() ? 0 : livebuilding.top().first;
            if(result.empty() || h != result.back().second)
                result.push_back({x, h});
            
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

