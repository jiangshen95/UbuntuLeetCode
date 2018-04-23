#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> num(n, true);
        for(int i=2;i<=sqrt(n);i++){
            if(num[i]){
                for(int j=i*i;j<n;j+=i){
                    num[j] = false;
                }
            }
        }
        int count = 0;
        for(int i=2;i<n;i++) {
            if(num[i]) count ++;
        }
        return count;
    }
};

int main(){
    
    int n;
    cin>>n;
    
    Solution *solution = new Solution();
    cout<<solution->countPrimes(n);
    
    return 0;
    
}
