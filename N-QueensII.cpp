#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int totalNQueens(int n) {

        vector<vector<char> > board;
        for(int i=0;i<n;i++){
            vector<char> s;
            for(int j=0;j<n;j++){
                s.push_back('.');
            }
            board.push_back(s);
        }
        
        int total=0;
        solveNQueens(total,board,0,n);
        
        return total;
    }

    void solveNQueens(int& total,vector<vector<char> >& board,int row,int n){
		
		for(int i=0;i<n;i++){
			if(board[row][i]=='.'&&isValid(board,row,i,n)){
				board[row][i]='Q';
				if(row==n-1){
					total++;
				}
				else{
					solveNQueens(total,board,row+1,n);
				}
				board[row][i]='.';
			}
		}
		
    }

    bool isValid(vector<vector<char> >& board,int x,int y,int n){

        for(int i=0;i<n;i++){
            if(board[x][i]!='.') return false;
            if(board[i][y]!='.') return false;
            if(i+(y-x)>=0&&i+(y-x)<n&&board[i][i+(y-x)]!='.') return false;
            if(n-i-1-(n-x-y-1)>=0&&n-i-1-(n-x-y-1)<n&&board[i][n-i-1-(n-x-y-1)]!='.') return false;
        }

        return true;

    }
};

int main(){

    int n;
    cin>>n;

    Solution *solution=new Solution();
    cout<<solution->totalNQueens(n);

    return 0;

}
