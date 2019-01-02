#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char> >& board) {
        int count = 0;
        for(int i = 0; i < board.size(); i++) {
        	for(int j = 0; j < board[i].size(); j++) {
//        		if(board[i][j] == 'X' && !((j > 0 && board[i][j - 1] == 'X') || (i > 0 && board[i - 1][j] == 'X')))
        		if(board[i][j] == 'X' && ((j == 0 || board[i][j - 1] != 'X') && (i == 0 || board[i - 1][j] != 'X')))
        			count++;
			}
		}
		
		return count;
    }
};

int main() {
	
	int m, n;
	cin>>m>>n;
	
	vector<vector<char> > board;
	for(int i = 0; i < m; i++) {
		vector<char> row;
		for(int j = 0; j < n; j++) {
			char x;
			cin>>x;
			row.push_back(x);
		}
		board.push_back(row);
	}
	
	Solution *solution = new Solution();
	cout<<solution->countBattleships(board)<<endl;
	
	return 0;
}
