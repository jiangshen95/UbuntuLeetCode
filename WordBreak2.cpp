#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        vector<bool> dp(s.length()+1, false);
        dp[0] = true;
        
        for(int i=1;i<=s.length();i++){
            
            for(int j=i-1;j>=0;j--){
                if(dp[j]){
                    int k;
                    for(k=0;k<wordDict.size();k++){
                        if(s.substr(j, i-j)==wordDict[k]){
                            dp[i] = true;
                            break;
                        }
                    }
                    if(k<wordDict.size()) break;
                }
            }
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
