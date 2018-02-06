#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> unvisited;
        vector<string> tovisit;
        int step=1;
        
        for(int i=0;i<wordList.size();i++){
            unvisited.insert(wordList[i]);
        }
        
        if(unvisited.count(beginWord)>0) unvisited.erase(beginWord);
        
        tovisit.push_back(beginWord);
        
        while(!tovisit.empty()){
            int size=tovisit.size();
            for(int i=0;i<size;i++){
                string word=tovisit[i];
                if(word==endWord) return step;
                
                for(int j=0;j<word.length();j++){
                    string temp=word;
                    for(int k=0;k<26;k++){
                        if(temp[j]=='a'+k) continue;
                        temp[j] = 'a'+k;
                        if(unvisited.count(temp)>0){
                            tovisit.push_back(temp);
                            unvisited.erase(temp);
                        }
                    }
                }
            }
            tovisit.erase(tovisit.begin(), tovisit.begin()+size);
            step++;
        }
        
        return 0;
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
    cout<<solution->ladderLength(beginWord, endWord, wordList);
    
    return 0;
}
