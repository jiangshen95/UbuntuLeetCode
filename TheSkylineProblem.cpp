/*
 * Fail to solut this question
 */
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        int n = buildings.size();
        vector<pair<int, int> > result;
        int l = buildings[0][0];
        int r = buildings[0][1];
        int h = buildings[0][2];
        result.push_back(pair<int, int>(l, h));
        for(int i=1;i<n;i++){
            
            if(buildings[i][0] > r){
                result.push_back(pair<int, int>(r, 0));
                l = buildings[i][0];
                r = buildings[i][1];
                h = buildings[i][2];
                result.push_back(pair<int, int>(l, h));
            }else if(buildings[i][1] <= r){
                if(buildings[i][2] <= h) continue;
                else{
                    result.push_back(pair<int, int>(buildings[i][0], buildings[i][2]));
                    l = buildings[i][0];
                    //r = buildings[i][1];
                    h = buildings[i][2];
                }
            }else{
                if(buildings[i][2] == h) {
                    r = buildings[i][1];
                    continue;
                }else if(buildings[i][2] < h){
                    result.push_back(pair<int, int>(r, buildings[i][2]));
                }else{
                    result.push_back(pair<int, int>(buildings[i][0], h));
                }
                r = buildings[i][1];
                h = min(h, buildings[i][2]);
            }
            //result.push_back(pair<int, int>(r, h));
        }
        
        result.push_back(pair<int, int>(r, 0));
        
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
