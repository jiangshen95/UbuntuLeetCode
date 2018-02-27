#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        vector<bool> dp(s.length(), false);
        
        for(int i=0;i<s.length();i++){
            
            for(int j=0;j<wordDict.size();j++){
                if(i+1>=wordDict[j].length() && s.substr(i+1-wordDict[j].length(), wordDict[j].length())==wordDict[j] && ((i+1>wordDict[j].length()&&dp[i-wordDict[j].length()]) || i+1==wordDict[j].length()) ){
                    dp[i] = true;
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
