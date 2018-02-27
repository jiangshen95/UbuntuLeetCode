#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        vector<bool> dp(s.length(), false);
        
        for(int i=1;i<=s.length();i++){
            for(int j=0;j<wordDict.size();j++){
                if(s.substr(0, i)==wordDict[j]){
                    dp[i-1] = true;
                    break;
                }
                for(int k=0;k<i;k++){
                    if(dp[k]&&s.substr(k+1, i-1-k)==wordDict[j]){
                        dp[i-1] = true;
                        break;
                    }
                }
            }
        }
        
        for(int i=0;i<s.length();i++){
            cout<<dp[i]<<" ";
        }
        
        return dp.back();
        
    }
};

int main(){
    string s;
    cin>>s;
    vector<string> wordDict;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string word;
        cin>>word;
        wordDict.push_back(word);
    }
    
    Solution *solution=new Solution();
    solution->wordBreak(s, wordDict) ? cout<<"True" : cout<<"False";
    
    return 0;
}
