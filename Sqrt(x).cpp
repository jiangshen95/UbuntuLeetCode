/*
 * Time Limit Exceeded
*/
#include<iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        
        for(int i=0;i<=x;i++){
            if(i*i==x || (i*i<x&&(i+1)*(i+1)>x)){
                return i;
            }
        }
        return x;
        
    }
};

int main(){
    int x;
    cin>>x;
    
    Solution *solution=new Solution();
    cout<<solution->mySqrt(x);
    
    return 0;
}
