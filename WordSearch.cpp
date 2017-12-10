#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char> >& board, string word) {
        int m=board.size(), n=board[0].size();
        vector<vector<bool> > inword(m, vector<bool>(n, false));
        
        return exist(0, word, board, inword, 0, 0);
    }
    
    bool exist(int curr, string word, vector<vector<char> >& board, vector<vector<bool> >& inword, int x, int y) {
        if(curr==0){
            for(int i=0;i<board.size();i++){
                for(int j=0;j<board[i].size();j++){
                    if(board[i][j]==word[curr]){
                        inword[i][j]=true;
                        if(exist(curr+1, word, board, inword, i, j)){
                            return true;
                        }
                        inword[i][j]=false;
                    }
                }
            }
            return false;
        }else{
            
            if(curr==word.length()){
                return true;
            }
            
            if(y<board[x].size()-1&&board[x][y+1]==word[curr]&&!inword[x][y+1]){
                inword[x][y+1]=true;
                if(exist(curr+1, word, board, inword, x, y+1)){
                    return true;
                }
                inword[x][y+1]=false;
            }
            if(x<board.size()-1&&board[x+1][y]==word[curr]&&!inword[x+1][y]){
                inword[x+1][y]=true;
                if(exist(curr+1, word, board, inword, x+1, y)){
                    return true;
                }
                inword[x+1][y]=false;
            }
            if(y>=1&&board[x][y-1]==word[curr]&&!inword[x][y-1]){
                inword[x][y-1]=true;
                if(exist(curr+1, word, board, inword, x, y-1)){
                    return true;
                }
                inword[x][y-1]=false;
            }
            if(x>=1&&board[x-1][y]==word[curr]&&!inword[x-1][y]){
                inword[x-1][y]=true;
                if(exist(curr+1, word, board, inword, x-1, y)){
                    return true;
                }
                inword[x-1][y]=false;
            }
            
            return false;
            
        }
    }
};

int main(){
    int m, n;
    cin>>m>>n;
    
    vector<vector<char> > board;
    for(int i=0;i<m;i++){
        vector<char> row;
        for(int j=0;j<n;j++){
            char ch;
            cin>>ch;
            row.push_back(ch);
        }
        board.push_back(row);
    }
    
    string word;
    cin>>word;
    
    Solution *solution=new Solution();
    
    solution->exist(board, word) ? cout<<"True" : cout<<"False";
    
    return 0;
}
