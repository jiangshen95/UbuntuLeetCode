#include<iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        return n == 0 ? 0 : n/5 + trailingZeroes(n/5);
    }
};

int main(){
    int n;
    cin>>n;
    
    Solution solution = Solution();
    cout<<solution.trailingZeroes(n);
    
    return 0;
}
