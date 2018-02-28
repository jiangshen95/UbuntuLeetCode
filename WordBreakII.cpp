/*
 * Time Limit Exceeded
*/
#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> words;
        vector<string> result;
        wordBreak(s, words, wordDict, result);
        
        return result;
    }
    
    void wordBreak(string s, vector<string>& words, vector<string>& wordDict, vector<string>& result){
        if(s==""){
            string sentence="";
            for(int i=0;i<words.size()-1;i++) sentence += words[i]+" ";
            sentence += words.back();
            result.push_back(sentence);
        }
        for(int i=0;i<wordDict.size();i++){
            /*int j;
            for(j=0;j<words.size();j++){
                if(wordDict[i]==words[j]) break;
            }
            if(j<words.size()) continue;*/
            
            if(s.substr(0, wordDict[i].length())==wordDict[i]){
                words.push_back(wordDict[i]);
                wordBreak(s.substr(wordDict[i].length()), words, wordDict, result);
                words.pop_back();
            }
        }
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
    vector<string> result = solution->wordBreak(s, wordDict);
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
    
    return 0;
}
