#include<iostream>
#include<string>
#include<vector>

using namespace std;

struct TrieNode {
public:
    string str;
    TrieNode* children[26] = {NULL};
};

class Trie {
public:
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *node = root;
        for(unsigned int i=0;i<word.length();i++){
            if(node->children[word[i] - 'a'] == NULL){
                node->children[word[i] - 'a'] = new TrieNode();
            }
            node = node->children[word[i] - 'a'];
        }
        node->str = word;
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
                if(trie->root->children[board[i][j] - 'a'] != NULL){
                    searchWord(result, board, m, n, i, j, visited, trie->root->children[board[i][j] - 'a']);
                }
            }
        }
        
        return result;
    }
    
    void searchWord(vector<string>& result, vector<vector<char> >& board, int m, int n, int x, int y, vector<vector<bool> >& visited, TrieNode *node) {
        if(visited[x][y]) return;
        if(node == NULL) return;
        if(!node->str.empty()){
            result.push_back(node->str);
            node->str.clear();
        }
        visited[x][y] = true;
        int to[][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        for(int i=0;i<4;i++){
            if(x+to[i][0] >=0 && x+to[i][0] < m && y + to[i][1] >= 0 && y + to[i][1] < n){
                searchWord(result, board, m, n, x + to[i][0], y + to[i][1], visited, node->children[board[x + to[i][0]][y + to[i][1]] - 'a']);
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
