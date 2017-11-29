#include<iostream>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if(n<3) return n;
        int a=1, b=2;
        int step;
        for(int i=3;i<=n;i++){
            step=a+b;
            a=b;
            b=step;
        }
        
        return step;
    }
};

int main(){
    int n;
    cin>>n;
    
    Solution *solution=new Solution();
    cout<<solution->climbStairs(n);
    
    return 0;
}
