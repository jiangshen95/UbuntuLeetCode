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
        
        vector<int> j_stack;
        
        int i=0;
        int j=0;
        while(i<n){
			for(;j<n;j++){
				if(board[i][j]=='.'&&isValid(board,i,j,n)){
					board[i][j]='Q';
					j_stack.push_back(j);
					break;
				}
			}
			
			if(j>=n){
				if(i==0){
					break;
				}
				i--;
				j=j_stack.back();
				j_stack.pop_back();
				board[i][j]='.';
				j++;
			}
			else{
				if(i==n-1){
					result.push_back(board);
					board[i][j]='.';
					
					j_stack.pop_back();
					
					if(j_stack.empty()){
						break;
					}
					

					i--;
					j=j_stack.back();
					j_stack.pop_back();
					board[i][j]='.';
						
					j++;
					
				}else{
					i++;
					j=0;
				}
			}
		}
        
        
        
        return result;
		
    }
    
    void clean_board(vector<string>& board){
		for(int i=0;i<board.size();i++){
			for(int j=0;j<board[i].length();j++){
				board[i][j]='.';
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
