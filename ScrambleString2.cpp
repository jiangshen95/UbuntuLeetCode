#include<iostream>
#include<string.h>

using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        
        if(s1.length()!=s2.length()) return false;
        if(s1==s2) return true;
        
        int l=s1.length();
        
        bool dp[l][l][l+1];
        
        for(int i=0;i<s1.length();i++){
            for(int j=0;j<s2.length();j++){
                for(int k=0;k<=l;k++){
                    dp[i][j][k]=false;
                }
                dp[i][j][1]=(s1[i]==s2[j]);
            }
        }
        
        for(int len=2;len<=s1.length();len++){
            for(int i=0;i<s1.length()-len+1;i++){
                for(int j=0;j<s2.length()-len+1;j++){
                    for(int k=1;k<len;k++){
                        dp[i][j][len] |= dp[i][j][k]&&dp[i+k][j+k][len-k]||dp[i][j+len-k][k]&&dp[i+k][j][len-k];
                    }
                }
            }
        }
        
        return dp[0][0][l];
    }
};

int main(){
    string s1, s2;
    cin>>s1>>s2;
    
    Solution *solution=new Solution();
    solution->isScramble(s1, s2)?cout<<"True":cout<<"False";
    
    return 0;
}
