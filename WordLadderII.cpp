/*
 * Time Limit Exceeded
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<string> > findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string> > result;
        vector<string> transforms;
        transforms.push_back(beginWord);
        findLadders(result, transforms, beginWord, endWord, wordList);
        return result;
    }
    
    void findLadders(vector<vector<string> >& result, vector<string>& transforms, string beginWord, string endWord, vector<string>& wordList){
        if(beginWord==endWord){
            while(!result.empty()){
                if(result.back().size()>transforms.size())
                    result.pop_back();
                else break;
            }
            if(result.empty()||((!result.empty())&&result.back().size()==transforms.size())) result.push_back(transforms);
            return;
        }
        for(int i=0;i<wordList.size();i++){
            if(isTransformed(beginWord, wordList[i])){
                bool hadAdd=false;
                for(int j=0;j<transforms.size();j++){
                    if(wordList[i]==transforms[j]){
                        hadAdd=true;
                        break;
                    }
                }
                if(!hadAdd){
                    transforms.push_back(wordList[i]);
                    findLadders(result, transforms, wordList[i], endWord, wordList);
                    transforms.pop_back();
                }
            }
        }
    }
    
    bool isTransformed(string w1, string w2){
        int count=0;
        for(int i=0;i<w1.length();i++){
            if(w1[i]!=w2[i]) count++;
            if(count>1) return false;
        }
        if(count==1) return true;
        else return false;
    }
};

int main(){
    string beginWord;
    cin>>beginWord;
    string endWord;
    cin>>endWord;
    
    int n;
    cin>>n;
    vector<string> wordList;
    for(int i=0;i<n;i++){
        string word;
        cin>>word;
        wordList.push_back(word);
    }
    
    Solution *solution=new Solution();
    vector<vector<string> > result = solution->findLadders(beginWord, endWord, wordList);
    
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
