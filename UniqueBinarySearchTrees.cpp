#include<iostream>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        dp[0]=dp[1]=1;
        for(int i=2;i<=n;i++){
            int num=0;
            for(int j=0;j<i;j++){
                num+=dp[j]*dp[i-j-1];
            }
            dp[i]=num;
        }
        
        for(int i=0;i<=n;i++) cout<<dp[i]<<" ";
        
        return dp[n];
    }
};

int main(){
    int n;
    cin>>n;
    
    Solution *solution=new Solution();
    cout<<solution->numTrees(n);
    
    return 0;
}
