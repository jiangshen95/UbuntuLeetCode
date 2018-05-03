#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

class Solution {
public:
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        if(buildings.size() == 0) return vector<pair<int, int> >();
        return recurSkyline(buildings, 0, buildings.size() - 1);
    }
    
    vector<pair<int, int> > recurSkyline(vector<vector<int> >& buildings, int p, int q){
        
        if(p < q){
            int mid = p + (q - p) / 2;
            return merge(recurSkyline(buildings, p, mid), recurSkyline(buildings, mid + 1, q));
        }else{
            vector<pair<int, int> > result;
            result.push_back({buildings[p][0], buildings[p][2]});
            result.push_back({buildings[p][1], 0});
            return result;
        }
    }
    
    vector<pair<int, int> > merge(vector<pair<int, int> > l1, vector<pair<int, int> > l2){
        
        vector<pair<int, int> > result;
        int i1 = 0, i2 = 0;
        int h1 = 0, h2 = 0;
        while(i1 < l1.size() && i2 < l2.size()){
            int x = 0, h = 0;
            if(l1[i1].first < l2[i2].first){
                x = l1[i1].first;
                h1 = l1[i1].second;
                h = max(h1, h2);
                i1 ++;
            }else if(l1[i1].first > l2[i2].first){
                x = l2[i2].first;
                h2 = l2[i2].second;
                h = max(h1, h2);
                i2 ++;
            }else{
                x = l1[i1].first;
                h1 = l1[i1].second;
                h2 = l2[i2].second;
                h = max(h1, h2);
                i1 ++;
                i2 ++;
            }
            
            if(result.empty() || h != result.back().second){
                result.push_back({x, h});
            }
        }
        
        while(i1 < l1.size()){
            result.push_back(l1[i1]);
            i1 ++;
        }
        
        while(i2 < l2.size()) {
            result.push_back(l2[i2]);
            i2 ++;
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

