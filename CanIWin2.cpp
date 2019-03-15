/*
* Time Limit Exceeded
*/
#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
    	if(maxChoosableInteger >= desiredTotal) return true;
    	if((1 + maxChoosableInteger) * maxChoosableInteger / 2 < desiredTotal) return false;
    	
    	unordered_map<int, bool> m;
    	// vector<int> m(1 << maxChoosableInteger, -1); 
    	
		return canIWin(maxChoosableInteger, desiredTotal, 0, m);
    }
    
    bool canIWin(int maxChoosableInteger, int total, int used, unordered_map<int, bool>& m) {
    	if(m.find(used) != m.end()) return m[used];
    	for(int i = maxChoosableInteger; i > 0; i--) {
    		int cur = (1 << (i - 1));
    		if(!(cur & used)) {
    			if(total - i <= 0 || !canIWin(maxChoosableInteger, total - i, used | cur, m)) {
    				m[used] = true;
    				return true;
				}
			}
		}
		m[used] = false;
		return false;
	}
};

int main() {
	
	int maxChoosableInteger, desiredTotal;
	cin>>maxChoosableInteger>>desiredTotal;
	
	Solution *solution = new Solution();
	solution->canIWin(maxChoosableInteger, desiredTotal) ? cout<<"true" : cout<<"false";
	
	return 0;
	
}
