#include<iostream>
#include<string.h>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int m=word1.length(), n=word2.length();
        int dp[m+1][n+1];
        for(int i=0;i<=n;i++) dp[0][i]=i;
        for(int i=0;i<=m;i++) dp[i][0]=i;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=min(dp[i][j-1]+1, dp[i-1][j]+1, dp[i-1][j-1]);
                }else{
                    dp[i][j]=min(dp[i][j-1]+1, dp[i-1][j]+1, dp[i-1][j-1]+1);
                }
                
            }
        }
        
        return dp[m][n];
        
    }
    
    int min(int x, int y, int z){
        return (x>y ? y : x)>z ? z : (x>y ? y : x);
    }
};

int main(){
    string word1, word2;
    cin>>word1;
    cin>>word2;
    
    Solution *solution=new Solution();
    cout<<solution->minDistance(word1, word2);
    
    return 0;
}
