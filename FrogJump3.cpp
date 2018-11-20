#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>

using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
    	
    	unordered_map<int, unordered_set<int> > m;
    	for(int s : stones) m[s] = unordered_set<int>();
    	m[0].insert(1);
    	
    	for(int s : stones) {
    		for(int k : m[s]) {
    			cout<<"k: "<<k<<"  s: "<<s<<endl;
    			if(k + s == stones.back()) return true;
    			if(m.find(k + s) != m.end()) {
    				m[k + s].insert(k);
    				if(k - 1 > 0) m[k + s].insert(k - 1);
    				m[k + s].insert(k + 1);
				}
			}
		}
    	
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
