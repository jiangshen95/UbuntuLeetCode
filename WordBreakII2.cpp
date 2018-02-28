#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        unordered_map<string, vector<string> > map;
        
        return wordBreak(s, wordDict, map);
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict, unordered_map<string, vector<string> >& map){
        
        if(map.find(s)!=map.end()) return map[s];
        
        vector<string> result;
        if(s.length()==0){
            result.push_back("");
            return result;
        }
        for(int i=0;i<wordDict.size();i++){
            if(s.substr(0, wordDict[i].length())==wordDict[i]){
                vector<string> sublist = wordBreak(s.substr(wordDict[i].length()), wordDict, map);
                for(int j=0;j<sublist.size();j++){
                    string sentence = wordDict[i] + (sublist[j].length() ? " " : "") + sublist[j];
                    result.push_back(sentence);
                }
            }
        }
        map[s] = result;
        return result;
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
