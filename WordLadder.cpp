#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //vector<int> ladder(wordList.size(), 2147483647);
        unordered_set<string> unvisited;
        unordered_set<string> current_step;
        unordered_set<string> next_step;
        int step=1;
        
        for(int i=0;i<wordList.size();i++){
            unvisited.insert(wordList[i]);
        }
        
        if(unvisited.count(beginWord)>0) unvisited.erase(beginWord);
        current_step.insert(beginWord);
        
        while(current_step.count(endWord)==0&&unvisited.size()>0&&current_step.size()>0){
            for(auto it=current_step.begin();it!=current_step.end();it++){
                string word=*it;
                for(int i=0;i<word.length();i++){
                    string temp=word;
                    for(int j=0;j<26;j++){
                        if(temp[i]=='a'+j) continue;
                        temp[i]='a'+j;
                        if(unvisited.count(temp)>0){
                            next_step.insert(temp);
                            unvisited.erase(temp);
                        }
                    }
                }
            }
            
            step++;
            current_step=next_step;
            next_step.clear();
        }
        if(current_step.count(endWord)>0) return step;
        else return 0;
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
