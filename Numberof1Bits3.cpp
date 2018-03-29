#include<iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int count = 0;
        
        while(n != 0){
            count ++;
            n &= (n-1);
        }
        
        return count;
        
    }
};

int main(){
    
    uint32_t n;
    cin>>n;
    
    Solution *solution = new Solution();
    cout<<solution->hammingWeight(n);
    
    return 0;
    
}
