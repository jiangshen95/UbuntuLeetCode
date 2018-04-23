#include<iostream>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        
        return n > m ? (rangeBitwiseAnd(m/2, n/2) << 1) : m;
        
    }
};

int main(){
    
    int m, n;
    cin>>m>>n;
    
    Solution *solution = new Solution();
    cout<<solution->rangeBitwiseAnd(m, n);
    
    return 0;
    
}
