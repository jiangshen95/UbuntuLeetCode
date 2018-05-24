#include<iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n <= 0) return false;
        int mask = 1, k = n;
        while(k > 1){
            if(k & mask) return false;
            k >>= 1;
        }
        
        return true;
        
    }
};

int main(){
    
    int n;
    cin>>n;
    
    Solution *solution = new Solution();
    solution->isPowerOfTwo(n) ? cout<<"True" : cout<<"False";
    
    return 0;
    
}
