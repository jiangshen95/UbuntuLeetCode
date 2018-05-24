#include<iostream>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        
        int count = 0;
        int q = n, x = 1;
        do {
            int d = q % 10;
            q /= 10;
            count += q * x;
            if(d == 1) count += n % x + 1;
            if(d > 1) count += x;
            x *= 10;
            
        }while(q > 0);
        
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
