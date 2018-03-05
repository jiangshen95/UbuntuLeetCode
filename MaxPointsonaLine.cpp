#include<iostream>
#include<vector>
#include<map>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point>& points) {
        int result = 0;
        for(int i=0;i<points.size();i++) {
            map<pair<int, int>, int> map;
            int duplicate = 1;
            for(int j=i+1;j<points.size();j++){
                if(points[i].x == points[j].x && points[i].y == points[j].y){
                    duplicate++;
                    continue;
                }
                int dx = points[j].x - points[i].x;
                int dy = points[j].y - points[i].y;
                int d = gcd(dx, dy);
                map[{dx/d, dy/d}]++;
            }
            result = max(result, duplicate);
            for(auto it=map.begin();it!=map.end();it++){
                result = max(result, it->second + duplicate);
            }
        }
        
        return result;
        
    }
    
    int gcd(int a, int b){
        return b==0 ? a : gcd(b, a%b);
    }
};

int main(){
    int n;
    cin>>n;
    
    vector<Point> points;
    for(int i=0;i<n;i++){
        int x, y;
        cin>>x>>y;
        Point point = Point(x, y);
        points.push_back(point);
    }
    
    Solution *solution = new Solution();
    cout<<solution->maxPoints(points);
    
    return 0;
}
