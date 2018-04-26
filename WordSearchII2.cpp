#include<iostream>
#include<string>
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
    TrieNode *endNode;
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
        endNode = node;
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

class Solution {
public:
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        
        Trie *trie = new Trie();
        for(auto word : words) trie->insert(word);
        
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool> > visited(m, vector<bool>(n, false));
        vector<string> result;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                searchWord(result, board, m, n, i, j, visited, "", trie);
            }
        }
        
        return result;
    }
    
    void searchWord(vector<string>& result, vector<vector<char> >& board, int m, int n, int x, int y, vector<vector<bool> >& visited, string str, Trie *trie) {
        if(visited[x][y]) return;
        str += board[x][y];
        if(trie->search(str)){
            result.push_back(str);
            trie->endNode->isEnd = false;
        }
        if(!trie->startsWith(str)) return;
        visited[x][y] = true;
        int to[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for(int i=0;i<4;i++){
            if(x+to[i][0] >=0 && x+to[i][0] < m && y + to[i][1] >= 0 && y + to[i][1] < n){
                searchWord(result, board, m, n, x + to[i][0], y + to[i][1], visited, str, trie);
            }
        }
        visited[x][y] = false;
        
    }
};

int main(){
    
    int m, n;
    cin>>m>>n;
    
    vector<vector<char> > board;
    for(int i=0;i<m;i++){
        vector<char> raw;
        for(int j=0;j<n;j++){
            char ch;
            cin>>ch;
            raw.push_back(ch);
        }
        board.push_back(raw);
    }
    
    int nw;
    cin>>nw;
    
    vector<string> words;
    for(int i=0;i<nw;i++){
        string word;
        cin>>word;
        words.push_back(word);
    }
    
    Solution *solution = new Solution();
    vector<string> result = solution->findWords(board, words);
    
    for(unsigned int i=0;i<result.size();i++) cout<<result[i]<<endl;
    
    return 0;
    
}
