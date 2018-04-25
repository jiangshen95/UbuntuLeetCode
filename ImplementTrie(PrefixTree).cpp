#include<iostream>
#include<unordered_map>

using namespace std;

class Trie {
public:
    /** Initialize your data structure here. */
    bool isEnd;
    unordered_map<char, Trie*> children;
    Trie() {
        isEnd = false;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        if(word.length() == 0){
            isEnd = true;
            return;
        }
        if(children.find(word[0]) == children.end()){
            children[word[0]] = new Trie();
        }
        children[word[0]]->insert(word.substr(1));
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        if(word.length() == 0 && isEnd) return true;
        if(word.length() == 0) return false;
        if(children.find(word[0]) == children.end()) return false;
        return children[word[0]]->search(word.substr(1));
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if(prefix.length() == 0) return true;
        if(children.find(prefix[0]) == children.end()) return false;
        return children[prefix[0]]->startsWith(prefix.substr(1));
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
