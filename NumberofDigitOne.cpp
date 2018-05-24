#include<iostream>

using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        
        int count = 0, a = 1, b = 1;
        while(n > 0){
            count += (n + 8) / 10 * a + (n % 10 == 1) * b;
            b += n %10 * a;
            a *= 10;
            n /= 10;
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
