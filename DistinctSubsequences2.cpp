#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        
        int dp[ls+1][lt+1];
        
        for(int i=0;i<=ls;i++) dp[i][0]=1;
        
        for(int i=0;i<=ls;i++){
            for(int j=1;j<=lt;j++){
                dp[i][j]=0;
            }
        }
        
        for(int i=1;i<=ls;i++){
            for(int j=1;j<=lt;j++){
                if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                else dp[i][j]=dp[i-1][j];
            }
        }
        
        return dp[ls][lt];
    }
};

int main(){
    string s;
    cin>>s;
    string t;
    cin>>t;
    
    Solution *solution=new Solution();
    cout<<solution->numDistinct(s, t);
    
    return 0;
}
