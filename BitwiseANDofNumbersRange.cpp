#include<iostream>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        /*
         * Time Limit Exceeded
        int result = m;
        for(int i=m+1;i<=n;i++){
            result &= i;
        }
        
        return result;*/
        
        int mask = 2147483647;
        while((m & mask) != (n & mask)){
            mask <<= 1;
        }
        
        return m & mask;
    }
};

int main(){
    
    int m, n;
    cin>>m>>n;
    
    Solution *solution = new Solution();
    cout<<solution->rangeBitwiseAnd(m, n);
    
    return 0;
    
}
