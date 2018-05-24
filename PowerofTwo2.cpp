#include<iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        
        if(n <= 0) return false;
        
        return !(n & (n - 1));
        
    }
};

int main(){
    
    int n;
    cin>>n;
    
    Solution *solution = new Solution();
    solution->isPowerOfTwo(n) ? cout<<"True" : cout<<"False";
    
    return 0;
    
}
