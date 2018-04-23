#include<iostream>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        
        while(m < n) n = n & (n-1);
        
        return n;
        
    }
};

int main(){
    
    int m, n;
    cin>>m>>n;
    
    Solution *solution = new Solution();
    cout<<solution->rangeBitwiseAnd(m, n);
    
    return 0;
    
}
