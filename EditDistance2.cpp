#include<iostream>
#include<string.h>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        
        int m=word1.length(), n=word2.length();
        
        int dp[m+1];
        for(int i=0;i<=m;i++) dp[i]=i;
        
        for(int j=1;j<=n;j++){
            int pre=dp[0];
            dp[0]=j;
            for(int i=1;i<=m;i++){
                int temp=dp[i];
                if(word1[i-1]==word2[j-1]){
                    dp[i] = min(dp[i]+1, dp[i-1]+1, pre);
                }else{
                    dp[i] = min(dp[i]+1, dp[i-1]+1, pre+1);
                }
                pre = temp;
            }
        }
        
        return dp[m];
        
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
