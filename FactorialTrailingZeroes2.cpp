#include<iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int r = 0;
        while(n > 0){
            n /= 5;
            r += n;
        }
        
        return r;
    }
};

int main(){
    int n;
    cin>>n;
    
    Solution solution = Solution();
    cout<<solution.trailingZeroes(n);
    
    return 0;
}
