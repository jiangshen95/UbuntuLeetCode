#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution {
public:
    int findMinStep(string board, string hand) {
    	unordered_map<char, int> m;
    	for(char c : hand) m[c]++;
    	return findMinStep(board, m);
    }
    
    int findMinStep(string board, unordered_map<char, int>& m) {
    	if(board.empty()) return 0;
    	int j = 0, minstep = INT_MAX;
    	for(int i = 0; i <= board.size(); i++) {
    		if(i < board.size() && board[i] == board[j]) continue;
    		int need = 3 - (i - j);
    		if(need <= 0) {
    			int t = findMinStep(board.substr(0, j) + board.substr(i), m);
    			if(t != -1) minstep = min(minstep, t);
			}
    		if(need > 0) {
    			if(m[board[j]] >= need) {
    				m[board[j]] -= need;
    				int t = findMinStep(board.substr(0, j) + board.substr(i), m);
    				if(t != -1) minstep = min(minstep, t + need);
    				m[board[j]] += need;
				}
			}
			j = i;
		}
		return minstep != INT_MAX ? minstep : -1;
	}
};

int main() {
	string board, hand;
	cin>>board>>hand;
	
	Solution *solution = new Solution();
	cout<<solution->findMinStep(board, hand);
	
	return 0;
}
