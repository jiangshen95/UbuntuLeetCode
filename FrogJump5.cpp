#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
    	
    	unordered_map<int, unordered_set<int> > m;
    	m[0].insert(0);
    	
    	for(int s : stones) {
    		for(int k : m[s]) {
    			if(k - 1 > 0) m[s + k - 1].insert(k - 1);
    			m[s + k].insert(k);
    			m[s + k + 1].insert(k + 1);
			}
		}
    	
    	return m[stones.back()].size();
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
