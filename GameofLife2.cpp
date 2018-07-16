#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int> >& board) {
        
        int m = board.size();
		int n = board[0].size();
		
		for(int i=0;i<m;i++) {
			for(int j=0;j<n;j++) {
				int count = 0;
				for(int I=max(0, i-1);I<min(i+2, m);I++) {
					for(int J=max(0, j-1);J<min(j+2, n);J++) {
						count += board[I][J] & 1;
					}
				}
				if(count == 3 || count - board[i][j] == 3) board[i][j] |= 2;
			}
		}
		
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				board[i][j] >>= 1;
		
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
