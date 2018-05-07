#include<iostream>

using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        
        int bottom = max(B, F);
        int top = min(D, H);
        int left = max(A, E);
        int right = min(C, G);
        
        int x = 0, y = 0;
        if(top > bottom) x = top - bottom;
        if(right > left) y = right - left;
        
        return (C - A) * (D - B) + (G - E) * (H - F) - x * y;
        
    }
};

int main(){
    
    int a, b, c, d, e, f, g, h;
    cin>>a>>b>>c>>d>>e>>f>>g>>h;
    
    Solution *solution = new Solution();
    cout<<solution->computeArea(a, b, c, d, e, f, g, h);
    
    return 0;
    
}
