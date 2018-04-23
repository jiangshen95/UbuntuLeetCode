/*
 * Time Limit Exceeded
 */
#include<iostream>
#include<math.h>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        for(int i=2;i<n;i++)
            if(isPrime(i)) count ++;
        return count;
    }
    
    bool isPrime(int n){
        for(int i=2;i<=sqrt(n);i++)
            if(n%i == 0) return false;
        return true;
    }
};

int main(){
    
    int n;
    cin>>n;
    
    Solution *solution = new Solution();
    cout<<solution->countPrimes(n);
    
    return 0;
    
}
