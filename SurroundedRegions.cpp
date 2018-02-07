#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char> >& board) {
        if(board.empty()) return;
        int m=board.size(), n=board[0].size();
        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){
                dfsfind(board, 0, i);
            }
            if(board[m-1][i]=='O'){
                dfsfind(board, m-1, i);
            }
        }
        for(int i=1;i<m-1;i++){
            if(board[i][0]=='O') dfsfind(board, i, 0);
            if(board[i][n-1]=='O') dfsfind(board, i, n-1);
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O') board[i][j]='X';
                else if(board[i][j]=='U') board[i][j]='O';
            }
        }
    }
    
    void dfsfind(vector<vector<char> >& board, int x, int y){
        int m=board.size(), n=board[0].size();
        board[x][y] = 'U';
        if(x>0&&board[x-1][y]=='O') dfsfind(board, x-1, y);
        if(x<m-1&&board[x+1][y]=='O') dfsfind(board, x+1, y);
        if(y>0&&board[x][y-1]=='O') dfsfind(board, x, y-1);
        if(y<n-1&&board[x][y+1]=='O') dfsfind(board, x, y+1);
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
    
    Solution *solution=new Solution();
    solution->solve(board);
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}
