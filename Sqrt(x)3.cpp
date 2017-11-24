/*
 * 牛顿迭代法
*/
#include<iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        
        long r=x;
        while(r*r>x){
            r=(r+x/r)/2;
        }
        
        return r;
        
    }
};

int main(){
    int x;
    cin>>x;
    
    Solution *solution=new Solution();
    cout<<solution->mySqrt(x);
    
    return 0;
}

