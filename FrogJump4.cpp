#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
    	
    	if(stones[1] != 1) return false;
    	
    	unordered_set<int> s;
    	
    	for(int i = 0; i < stones.size(); i++) {
    		if(i > 3 && stones[i] > stones[i - 1] * 2) return false;
    		s.insert(stones[i]);
		}
    	
    	
    	
    	return canCross(s, stones.back(), 1, 0);
    	
    }
    
    bool canCross(unordered_set<int>& s, int last, int k, int num) {
    	if(num == last) return true;
    	
    	if(s.find(num + k + 1) != s.end() && canCross(s, last, k + 1, num + k + 1)) return true;
    	if(s.find(num + k) != s.end() && canCross(s, last, k, num + k)) return true;
    	if(k - 1 > 0 && s.find(num + k - 1) != s.end() && canCross(s, last, k - 1, num + k - 1)) return true;
    	
    	return false;
	}
};

int main() {
	
	int n;
	cin>>n;
	
	vector<int> stones;
	for(int i = 0; i < n; i++) {
		int num;
		cin>>num;
		stones.push_back(num);
	}
	
	Solution *solution = new Solution();
	solution->canCross(stones) ? cout<<"true" : cout<<"false";
	
	return 0;
}
