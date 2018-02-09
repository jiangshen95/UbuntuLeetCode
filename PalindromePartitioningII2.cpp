#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        vector<vector<bool> > pair(s.length(), vector<bool>(s.length(), false));
        
        for(int i=0;i<s.length();i++){
            for(int j=0;j<=i;j++){
                if(s[i]==s[j]&&(i-j<=1||pair[j+1][i-1])) pair[j][i]=true;
            }
        }
        
        vector<int> dp(s.length()+1);
        for(int i=0;i<=s.length();i++){
            dp[i]=s.length()-i-1;
        }
        
        for(int i=s.length()-1;i>=0;i--){
            for(int j=i;j<s.length();j++){
                if(pair[i][j]){
                    dp[i] = dp[j+1]+1<dp[i]?dp[j+1]+1:dp[i];
                    cout<<i<<"-------"<<dp[i]<<endl;
                }
            }
        }
        
        return dp[0];
    }
};

int main(){
    string s;
    cin>>s;
    
    Solution *solution=new Solution();
    cout<<solution->minCut(s);
    
    return 0;
}
