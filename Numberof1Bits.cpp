#include<iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        int count = 0;
        
        for(;n>0;n/=2){
            if(n%2 == 1) count++;
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
