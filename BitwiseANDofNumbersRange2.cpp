#include<iostream>

using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        
        int count = 0;
        while(m != n){
            m >>= 1;
            n >>= 1;
            count ++;
        }
        
        return m << count;
    }
};

int main(){
    
    int m, n;
    cin>>m>>n;
    
    Solution *solution = new Solution();
    cout<<solution->rangeBitwiseAnd(m, n);
    
    return 0;
    
}
