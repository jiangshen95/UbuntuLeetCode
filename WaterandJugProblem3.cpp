#include<iostream>
#include<queue>
#include<set>

using namespace std;

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
    	
    	if(x > y) swap(x, y);
    	
    	queue<pair<int, int> > q;
    	q.push(make_pair(0, 0));
    	set<pair<int, int> > visited;
    	visited.insert(make_pair(0, 0));
    	while(!q.empty()) {
    		pair<int, int> t = q.front();
    		q.pop();
    		
    		if(t.first + t.second == z) return true;
    		
    		set<pair<int, int> > states;
    		states.insert(make_pair(t.first, y));
    		states.insert(make_pair(x, t.second));
    		states.insert(make_pair(t.first, 0));
    		states.insert(make_pair(0, t.second));
    		states.insert(make_pair(min(x, t.first + t.second), t.first + t.second < x ? 0 : t.second - (x - t.first)));
    		states.insert(make_pair(t.first + t.second < y ? 0 : t.first - (y - t.second), min(y, t.first + t.second)));
    		
    		for(auto it : states) {
    			if(visited.find(it) == visited.end()) {
    				q.push(it);
    				visited.insert(it);
				}
			}
		}
		
		return false;
        
    }
    
};

int main() {
	
	int x, y, z;
	cin>>x>>y>>z;
	
	Solution *solution = new Solution();
	solution->canMeasureWater(x, y, z) ? cout<<"true" : cout<<"false";
	
	return 0;
} 
