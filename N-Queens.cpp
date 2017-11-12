#include<iostream>
#include<vector>
#include<string.h>

using namespace std;

class Solution {
public:
    vector<vector<string> > solveNQueens(int n) {

        vector<string> board;
        for(int i=0;i<n;i++){
            string s="";
            for(int j=0;j<n;j++){
                s+='.';
            }
            board.push_back(s);
        }
        
        vector<vector<string> > result;
        solveNQueens(result,board,0,n);
        
        return result;
		
		//~ board[0][1]='Q';
        //~ cout<<isValid(board,1,0,n)<<endl;

        //~ for(int i=0;i<n;i++){
            //~ for(int j=0;j<n;j++){
                //~ cout<<board[i][j]<<", ";
            //~ }
            //~ cout<<endl;
        //~ }
    }

    void solveNQueens(vector<vector<string> >& result,vector<string>& board,int row,int n){
		
		for(int i=0;i<n;i++){
			if(board[row][i]=='.'&&isValid(board,row,i,n)){
				board[row][i]='Q';
				if(row==n-1){
					result.push_back(board);
				}
				else{
					solveNQueens(result,board,row+1,n);
				}
				board[row][i]='.';
			}
		}
		
    }

    bool isValid(vector<string>& board,int x,int y,int n){

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
    vector<vector<string> > result=solution->solveNQueens(n);

    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            for(int k=0;k<result[i][j].length();k++){
                cout<<result[i][j][k]<<", ";
            }
            cout<<endl;
        }

        cout<<endl<<endl;
    }

    return 0;

}
