#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        vector<bool> num(n, true);
        int count = 0;
        for(int i=2;i<n;i++){
            if(num[i]){
                count ++;
                for(int j=2;i*j < n;j++){
                    num[i*j] = false;
                }
            }
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
