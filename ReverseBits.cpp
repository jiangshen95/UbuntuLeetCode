#include<iostream>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t rev = 0;
        uint32_t t = n;
        for(int i=0;i<32;i++){
            rev <<= 1;
            rev |= t%2;
            cout<<"rev: "<<rev<<endl;
            t = t/2;
        }
        
        return rev;
    }
};

int main(){
    
    uint32_t n;
    cin>>n;
    
    Solution *solution = new Solution();
    cout<<solution->reverseBits(n);
    
    return 0;
    
}
