#include<iostream>
#include<vector>

using namespace std;

class TrieNode {
public:
    bool isEnd;
    TrieNode* children[26] = {NULL};
    TrieNode(){
        isEnd = false;
    }
    
    bool containKey(char ch) {
        return children[ch - 'a'] != NULL;
    }
    
    TrieNode* get(char ch){
        return children[ch - 'a'];
    }
    
    void put(char ch) {
        children[ch - 'a'] = new TrieNode();
    }
    
    void setEnd(){
        isEnd = true;
    }
    
};

class Trie {
public:
    /** Initialize your data structure here. */
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *node = root;
        for(unsigned int i=0;i<word.length();i++){
            if(!node->containKey(word[i])) node->put(word[i]);
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *node = root;
        for(unsigned int i=0;i<word.length();i++) {
            if(!node->containKey(word[i])) return false;
            node = node->get(word[i]);
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *node = root;
        for(unsigned int i=0;i<prefix.length();i++) {
            if(!node->containKey(prefix[i])) return false;
            node = node->get(prefix[i]);
        }
        return true;
    }
};

int main(){
    
    Trie *trie = new Trie();
    trie->insert("hello");
    trie->search("hello") ? cout<<"True" : cout<<"False";
    cout<<endl;
    trie->search("hell") ? cout<<"True" : cout<<"False";
    cout<<endl;
    trie->search("hellw") ? cout<<"True" : cout<<"False";
    cout<<endl;
    trie->startsWith("hello") ? cout<<"True" : cout<<"False";
    cout<<endl;
    trie->startsWith("helso") ? cout<<"True" : cout<<"False";
    cout<<endl;
    
    return 0;
    
}
