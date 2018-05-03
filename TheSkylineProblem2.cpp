#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

class Solution {
public:
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        
        vector<pair<int, int> > heights;
        for(int i=0;i<buildings.size();i++){
            heights.push_back(pair<int, int>(buildings[i][0], -buildings[i][2]));
            heights.push_back(pair<int, int>(buildings[i][1], buildings[i][2]));
        }
        sort(heights.begin(), heights.end());
        
        multiset<int> heap;
        heap.insert(0);
        vector<pair<int, int> > res;
        int pre = 0, cur = 0;
        for(int i=0;i<heights.size();i++){
            if(heights[i].second < 0){
                heap.insert(-heights[i].second);
            }else{
                heap.erase(heap.find(heights[i].second));
            }
            cur = *heap.rbegin();
            if(cur != pre){
                res.push_back({heights[i].first, cur});
                pre = cur;
            }
        }
        
        return res;
        
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
