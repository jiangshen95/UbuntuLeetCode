#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        
        int ls=s.length(), lt=t.length(); 
        
        vector<int> dp(lt+1, 0);
        
        dp[0]=1;
        
        for(int i=1;i<=ls;i++){
            for(int j=lt;j>=1;j--){
                if(s[i-1]==t[j-1]) dp[j]+=dp[j-1];
            }
        }
        
        return dp[lt];
        
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
