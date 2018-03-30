#include<iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        n = (n & 0x55555555) + (n >> 1 & 0x55555555);
        n = (n & 0x33333333) + (n >> 2 & 0x33333333);
        n = (n & 0x0f0f0f0f) + (n >> 4 & 0x0f0f0f0f);
        n = (n & 0x00ff00ff) + (n >> 8 & 0x00ff00ff);
        n = (n & 0x0000ffff) + (n >> 16 & 0x0000ffff);
        
        return n;
        
    }
};

int main(){
    
    uint32_t n;
    cin>>n;
    
    Solution *solution = new Solution();
    cout<<solution->hammingWeight(n);
    
    return 0;
    
}