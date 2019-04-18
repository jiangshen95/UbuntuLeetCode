#include<iostream>
#include<algorithm>
#include<unordered_set>

using namespace std;

class Solution {
public:
    int findMinStep(string board, string hand) {
    	board = removeConsecutive(board);
    	cout<<"board: "<<board<<"  hand: "<<hand<<endl;
    	if(board == "") return 0;
    	int result = INT_MAX;
    	unordered_set<char> s;
    	for(int i = 0; i < hand.size(); i++) {
    		if(s.find(hand[i]) != s.end()) continue;
    		s.insert(hand[i]);
    		for(int j = 0; j < board.size(); j++) {
    			if(board[j] == hand[i]) {
    				int t = findMinStep(board.substr(0, j) + hand[i] + board.substr(j), hand.substr(0, i) + hand.substr(i + 1));
    				if(t != -1) result = min(result, t + 1);
				}
			}
		}
		return result == INT_MAX ? -1 : result;
    }
	
	string removeConsecutive(string board) {
		int count = 1;
		for(int i = 1; i <= board.size(); i++) {
			if(i < board.size() && board[i] == board[i - 1]) count++;
			else {
				if(count >= 3) return removeConsecutive(board.substr(0, i - count) + board.substr(i));
				count = 1;
			}
		}
		return board;
	}
};

int main() {
	string board, hand;
	cin>>board>>hand;
	
	Solution *solution = new Solution();
	cout<<solution->findMinStep(board, hand);
	
	return 0;
}
