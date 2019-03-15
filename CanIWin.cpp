/*
* Time Limit Exceeded
*/
#include<iostream>
#include<unordered_set>

using namespace std;

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
    	unordered_set<int> choosed;
        for(int i = maxChoosableInteger; i > 0; i--) {
        	if(i >= desiredTotal) return true;
        	choosed.insert(i);
        	if(!canIWin(maxChoosableInteger, desiredTotal, i, choosed)) return true;
        	choosed.erase(i);
		}
		
		return false;
    }
    
    bool canIWin(int maxChoosableInteger, int desiredTotal, int total, unordered_set<int>& choosed) {
    	for(int i = maxChoosableInteger; i > 0; i--) {
    		if(choosed.find(i) == choosed.end()) {
    			if(total + i >= desiredTotal) return true;
    			choosed.insert(i);
    			bool next = canIWin(maxChoosableInteger, desiredTotal, total + i, choosed);
    			choosed.erase(i);
    			if(!next) return true;
			}
		}
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
