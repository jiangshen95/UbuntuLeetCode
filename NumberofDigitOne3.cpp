#include<iostream>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        
        int count = 0;
        for(long k = 1;k <= n;k *= 10) {
            long divider = k * 10;
            count += (n / divider) * k + min(max(n % divider - k + 1, 0L), k);
        }
        
        return count;
        
    }
};

int main() {
    
    int n;
    cin>>n;
    
    Solution *solution = new Solution();
    cout<<solution->countDigitOne(n);
    
    return 0;
    
}
