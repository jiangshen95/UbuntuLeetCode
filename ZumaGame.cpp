#include<iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
    int findMinStep(string board, string hand) {
        if(board.empty()) return 0;
        cout<<"board: "<<board<<"  hand: "<<hand<<endl;
    	int count = 1, minstep = INT_MAX;
    	for(int i = 1; i <= board.size(); i++) {
    		if(i <board.size() && board[i] == board[i - 1]) count++;
    		else {
    			if(count >= 3) {
    				string afterzuma = board.substr(0, i - count) + board.substr(i);
    				int t = findMinStep(afterzuma, hand);
    				cout<<"--------------  "<<t<<"  ---------------"<<endl;
    				if(t != -1) minstep = min(minstep, t);
				}else {
//					if(i == board.size() && hand == "") return -1;
					if(count == 2) {
						for(int j = 0; j < hand.size(); j++) {
							if(hand[j] == board[i - 1]) {
								string afterzuma = board.substr(0, i - count) + board.substr(i);
								string h = hand.substr(0, j) + hand.substr(j + 1);
								int t = findMinStep(afterzuma, h);
								cout<<"--------------  "<<t<<"  ---------------"<<endl;
								if(t != -1) minstep = min(minstep, t + 1);
								break;
							}
						}
					}else {
						string h = "";
						int cnt = 0, j, pre = 0;
						for(j = 0; j < hand.size(); j++) {
							if(hand[j] == board[i - 1]) {
								h += hand.substr(pre, j - pre);
								pre = j + 1;
								if(++cnt == 2) break;
							}
						}
						if(cnt == 2) {
							string afterzuma = board.substr(0, i - count) + board.substr(i);
							h += hand.substr(j + 1);
							int t = findMinStep(afterzuma, h);
							cout<<"--------------  "<<t<<"  ---------------"<<endl;
							if(t != -1) minstep = min(minstep, t + 2);
						}
					}
				}
				count = 1;
			}
		}
		cout<<"this-board: "<<board<<"  this-hand: "<<hand<<endl;
		cout<<"minstep: "<<minstep<<endl;
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
