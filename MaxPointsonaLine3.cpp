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
            int duplicate = 1;
            for(int j=i+1;j<points.size();j++){
                int cnt = 0;
                long long x1 = points[i].x, y1 = points[i].y;
                long long x2 = points[j].x, y2 = points[j].y;
                if(x1 ==x2  &&y1 == y2){
                    duplicate++;
                    continue;
                }
                for(int k=0;k<points.size();k++){
                    int x3 = points[k].x, y3 = points[k].y;
                    if(x1*y2 - x1*y3 - x2*y1 + x2*y3 + x3*y1 - x3*y2 == 0){
                        cnt++;
                    }
                }
                result = max(result, cnt);
            }
            result = max(result, duplicate);
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
