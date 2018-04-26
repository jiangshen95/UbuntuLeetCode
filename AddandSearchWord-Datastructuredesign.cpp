#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct TrieNode {
    bool isEnd = false;
    TrieNode* children[26] = {NULL};
};

class WordDictionary {
public:
    TrieNode *root;
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *cur = root;
        for(int i=0;i<word.length();i++){
            if(cur->children[word[i] - 'a'] == NULL)
                cur->children[word[i] - 'a'] = new TrieNode();
            cur = cur->children[word[i] - 'a'];
        }
        cur->isEnd = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(root, word);
    }
    
    bool search(TrieNode *cur, string word) {
        //cout<<"word: "<<word<<endl;
        for(int i=0;i<word.length();i++){
            if(word[i] == '.'){
                for(int j=0;j<26;j++){
                    if(cur->children[j] != NULL){
                        if(search(cur->children[j], word.substr(i+1))) return true;
                    }
                }
                return false;
            }else{
                if(cur->children[word[i] - 'a'] != NULL) cur = cur->children[word[i] - 'a'];
                else return false;
            }
        }
        //cout<<"end: "<<cur->isEnd<<endl;
        return cur->isEnd;
    }
};

int main(){
    
    WordDictionary *dic = new WordDictionary();
    dic->addWord("bad");
    dic->addWord("dad");
    dic->addWord("mad");
    dic->search("pad") ? cout<<"true" : cout<<"false";
    cout<<endl;
    dic->search("bad") ? cout<<"true" : cout<<"false";
    cout<<endl;
    dic->search(".ad") ? cout<<"true" : cout<<"false";
    cout<<endl;
    dic->search("b..") ? cout<<"true" : cout<<"false";
    cout<<endl;
    
    return 0;
}
