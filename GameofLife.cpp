#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int> >& board) {
        
        int m = board.size();
		int n = board[0].size();
		
		vector<vector<int> > position{
			{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}
		};
		
		//2 : 1->0
		//3 : 0->1
		for(int i=0;i<m;i++) {
			for(int j=0;j<n;j++) {
				int count = 0;
				for(int k=0;k<8;k++) {
					if(i + position[k][0] >= 0 && i + position[k][0] < m && j + position[k][1] >= 0 && j + position[k][1] < n
						&& (board[i + position[k][0]][j + position[k][1]] == 1 || board[i + position[k][0]][j + position[k][1]] == 2))
						count ++;
				}
				if(board[i][j]) {
					if(count < 2 || count > 3) board[i][j] = 2;
				}else {
					if(count == 3) board[i][j] = 3;
				}
			}
		}
        
        for(int i=0;i<m;i++) {
        	for(int j=0;j<n;j++) {
        		if(board[i][j] == 2) board[i][j] = 0;
        		else if(board[i][j] == 3) board[i][j] = 1;
			}
		}
    }
};

int main() {
	
	int m, n;
	cin>>m>>n;
	
	vector<vector<int> > board;
	for(int i=0;i<m;i++) {
		vector<int> raw;
		for(int j=0;j<n;j++) {
			int cell;
			cin>>cell;
			raw.push_back(cell);
		}
		board.push_back(raw);
	}
	
	Solution *solution = new Solution();
	solution->gameOfLife(board);
	
	for(int i=0;i<m;i++) {
		for(int j=0;j<n;j++) {
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}
