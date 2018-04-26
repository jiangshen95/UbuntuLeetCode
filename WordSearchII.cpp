/*
 * Time Limit Exceeded
 */
#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> findWords(vector<vector<char> >& board, vector<string>& words) {
        
        vector<string> result;
        
        for(auto word : words){
            if(searchWord(board, word)){
                int j=0;
                for(;j<result.size();j++){
                    if(result[j] == word) break; 
                }
                if(j == result.size()) result.push_back(word);
            }
        }
        
        return result;
        
    }
    
    bool searchWord(vector<vector<char> >& board, string word) {
        int m = board.size();
        int n = board[0].size();
        if(word.length() > m * n) return false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == word[0]){
                    vector<vector<bool> > visited(m, vector<bool>(n, false));
                    if(searchWord(0, board, visited, m, n, word, i, j, 1)) return true;
                }
            }
        }
        return false;
    }
    
    bool searchWord(int from, vector<vector<char> >& board, vector<vector<bool> >& visited, int m, int n, string word, int x, int y, int k) {
        if(visited[x][y]) return false;
        if(k == word.length()) return true;
        visited[x][y] = true;
        if(x - 1 >=0 && board[x-1][y] == word[k]) {
            if(searchWord(1, board, visited, m, n, word, x - 1, y, k + 1)) return true;
        }
        if(y + 1 < n && board[x][y+1] == word[k]) {
            if(searchWord(2, board, visited, m, n, word, x, y + 1, k + 1)) return true;
        }
        if((from == 0 || from != 1) && x + 1 < m && board[x+1][y] == word[k]) {
            if(searchWord(3, board, visited, m, n, word, x + 1, y, k + 1)) return true;
        }
        if((from == 0 || from != 2) && y - 1 >= 0 && board[x][y-1] == word[k]) {
            if(searchWord(4, board, visited, m, n, word, x, y - 1, k + 1)) return true;
        }
        visited[x][y] = false;
        return false;
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
